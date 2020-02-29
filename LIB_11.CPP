#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

//global variables declaration
int cs=0;
int cb=0;
struct book
{
	char bname[100];
	char author[100];
	int bno,bavailable;
}b[100];
struct student
{
	char sname[100];
	int admno,token,stbno;
}s[100];


void create_student(int c)
{
	clrscr();
	cout<<"\n\n\t\t NEW STUDENT ENTRY :  ";
	cout<<"\n Name of the student : ";
	gets(s[c].sname);
	cout<<"\n Admission number : ";
	cin>>s[c].admno;
	s[c].stbno=0;
	s[c].token=0;
}


void create_book(int c)
{
	clrscr();
	cout<<"\n\n\t\t NEW BOOK ENTRY :\n";
	cout<<"\n Name : ";
	gets(b[c].bname);
	cout<<"\n Author : ";
	gets(b[c].author);
	cout<<"\n Book Number : ";
	cin>>b[c].bno;
	b[c].bavailable=0;
}


void show_book(int c)
{
	cout<<"\n Book Number   : "<<b[c].bno;
	cout<<"\n Book Name     : "<<b[c].bname;
	cout<<"\n Author's Name : "<<b[c].author;
}


void show_student(int c)
{
	cout<<"\n Admission No.  : "<<s[c].admno;
	cout<<"\n Student's Name : "<<s[c].sname;
}


void write_book()
{
	char ch;
	do
	{
		clrscr();
		create_book(cb);
		b[cb].bavailable=0;
		cb++;
		cout<<"\n Do you want to add more records(Y/N) :";
		cin>>ch;
	}while(ch=='y'|| ch=='Y');
}


void write_student()
{
	char ch;
	do
	{
		clrscr();
		create_student(cs);
		s[cs].token=0;
		s[cs].stbno=0;
		cs++;
		cout<<"\n Do you want to add more records(Y/N) :";
		cin>>ch;
	}while(ch=='y'|| ch=='Y');
}


void disp_sps(int n)
{
	cout<<"\n\t\t STUDENT DETAILS ...\n";
	int flag=0;
	for(int i=0;i<cs;i++)
	{
		if(s[i].admno==n)
		{
			show_student(i);
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n\n Student record does not exist\n";
	getch();
}


void disp_spb(int n)
{
	cout<<"\n\t\t BOOK DETAILS ...\n";
	int flag=0;
	for(int i=0;i<cb;i++)
	{
		if(b[i].bno==n)
		{
			show_book(i);
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n\n Book does not exist\n";
	getch();
}


void display_alls()
{
	clrscr();
	cout<<"\n\n STUDENTS LIST..\n";
	for(int i=0;i<cs;i++)
	{
		cout<<"\n STUDENT  "<<(i+1);
		show_student(i);
	}
	getch();
}



void display_allb()
{
	clrscr();
	cout<<"\n\n BOOKS LIST..\n";
	for(int i=0;i<cb;i++)
	{
		cout<<"\n BOOK  "<<(i+1);
		show_book(i);
	}
	getch();
}


void del_student()
{
	clrscr();
	int n,flag=0,i,pos;
	cout<<"\n\n DELETE STUDENT..\n";
	cout<<"\n Enter the admission no. of the student : ";
	cin>>n;
	for(i=0;i<cs;i++)
	{
		if(s[i].admno==n)
		{
			pos=i;
			flag=1;
			break;
		}

	}
	if(flag==1)
	{
		for(i=pos;i<cs-1;i++)
		{
			s[i]=s[i+1];
		}
		cs--;
		cout<<"\n Student record deleted";
	}
	else
		cout<<"Student record does not exist..";
	getch();
}


void del_book()
{
	clrscr();
	int n,flag=0,i,pos;
	cout<<"\n\n DELETE BOOK..\n";
	cout<<"\n Enter the book no. : ";
	cin>>n;
	for(i=0;i<cb;i++)
	{
		if(b[i].bno==n)
		{
			pos=i;
			flag=1;
			break;
		}

	}
	if(flag==1)
	{
		cout<<"\nBook record deleted..\n";
		for(i=pos;i<cb-1;i++)
		{
			b[i]=b[i+1];
		}
		cb--;
	}
	else
		cout<<"Book record does not exist..";
	getch();
}



void book_issue()
{
	int sn,bn;
	int found=0,flag=0;
	int i,j;
	clrscr();
	cout<<"\n\n\t\t BOOK ISSUE...\n";
	cout<<"\n Enter the admission no. of the student : ";
	cin>>sn;
	i=0;
	while(i<cs && found==0)
	{
		if(s[i].admno==sn)
		{
			found=1;
			if(s[i].token==0)
			{
				cout<<"\n\n Enter the book no. : ";
				cin>>bn;
				j=0;
				while(j<cb && flag==0)
				{
					if(b[j].bno==bn)
					{
						flag=1;
						if(b[j].bavailable==0)
						{
							cout<<"\n\n Book issued successfully";
							cout<<"\n Please Note : Write current date on the backside of the book";
							cout<<"\n Submit within 15 days else Rs.2 fine for each day after 15 days period\n";
							s[i].stbno=bn;
							b[j].bavailable++;
							s[i].token++;
						}
						else
							cout<<"\nBook has already been issued";
					}
					j++;
				}
				if(flag==0)
					cout<<"\nBook does not exist\n";
			}
			else
				cout<<"You have not returned the last book";
		}
		i++;
	}
	if(found==0)
		cout<<"Student record does not exist...";
	getch();
}


void book_deposit()
{
	int sn,bn;
	int found=0;
	int i,j,days;
	clrscr();
	cout<<"\n\n\t\t BOOK DEPOSIT...\n";
	cout<<"\n Enter the admission no. of the student : ";
	cin>>sn;
	i=0;
	while(i<cs && found==0)
	{
		if(s[i].admno==sn)
		{
			found=1;
			if(s[i].token!=0)
			{
				bn=s[i].stbno;
				j=0;
				while(j<cb)
				{
					if(b[j].bno==bn)
					{
						cout<<"\n\n Book deposited successfully";
						cout<<"\n Enter the no. of days for which the book had been issued : ";
						cin>>days;
						if(days<=15)
							cout<<"\n No fine due..\n";
						else
							cout<<"\n Pay the fine due of Rs."<<((days-15)*2)<<endl;
						s[i].stbno=0;
						b[j].bavailable--;
						s[i].token--;
						break;
					}
					j++;
				}
			}
			else
				cout<<"You have not issued any book. \n Please check!!";
		}
		i++;
	}
	if(found==0)
		cout<<"Student record does not exist...";
	getch();
}


void admin_menu()
{
	clrscr();
	int ch,n;
	do
	{       clrscr();
		cout<<"\n\n\t\t ADMINISTRATOR MENU...";
		cout<<"\n\n 1.Create Student Record";
		cout<<"\n\n 2.Display All Students Record";
		cout<<"\n\n 3.Display Specific Student Record";
		cout<<"\n\n 4.Delete Student Record";
		cout<<"\n\n 5.Create Book";
		cout<<"\n\n 6.Display All Books";
		cout<<"\n\n 7.Display Specific Book";
		cout<<"\n\n 8.Delete Book Record";
		cout<<"\n\n 9.Back To Main Menu";
		cout<<"\n\n Please Enter Your Choice (1-9) \n ";
		cin>>ch;
		switch(ch)
		{
			case 1:clrscr();
			       write_student();
			       break;
			case 2:clrscr();
			       display_alls();
			       break;
			case 3:clrscr();
			       cout<<"\n\n Please enter the admission no. :";
			       cin>>n;
			       disp_sps(n);
			       break;
			case 4:del_student();
			       break;
			case 5:clrscr();
			       write_book();
			       break;
			case 6:clrscr();
			       display_allb();
			       break;
			case 7:clrscr();
			       cout<<"\n\n Please enter the book no.  :";
			       cin>>n;
			       disp_spb(n);
			       break;
			case 8:del_book();
			       break;
			case 9:return;
			default:cout<<"Wrong choice";
		}
	}while(ch!=9);
	getch();
}


void main()
{
	char ch;
	do
	{
		clrscr();
		cout<<"\n\n\t\t\t LIBRARY MANAGEMET SYSTEM...\n";
		cout<<"\n\n\t\t MAIN MENU \n";
		cout<<"\n\n 01. BOOK ISSUE";
		cout<<"\n\n 02. BOOK DEPOSIT";
		cout<<"\n\n 03. ADMINISTRATOR MENU";
		cout<<"\n\n 04. EXIT";
		cout<<"\n\nPlease Select Your Option(1-4)\n ";
		cin>>ch;
		switch(ch)
		{
			case '1':clrscr();
				 book_issue();
				 break;
			case '2':clrscr();
				 book_deposit();
				 break;
			case '3':admin_menu();
				 break;
			case '4':exit(0);
			default :cout<<"\nWrong Choice\n";
		}
	}while(ch!='4');
}

