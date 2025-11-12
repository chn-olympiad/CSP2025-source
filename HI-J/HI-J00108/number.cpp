#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	int r=0;
	int a[100000];
	cin>>s;
	int cnt=0;
	int large=0;
	for(int i=0;i<=10000;i++)
	{
		a[i]=0;
	}
if(s.length()==1)
{
	cout<<s;
	}
	else
	{
			for(int i=0;i<=s.length();i++)
	{
	    if(s[i]=='1'||s[i]=='0'||s[i]=='8'||s[i]=='7'||s[i]=='6'||s[i]=='5'||s[i]=='4'||s[i]=='3'||s[i]=='2'||s[i]=='9')
	    {
	    	a[i]++;
	    	cnt++;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
	
	for(int i=0;i<=s.length();i++)
	{
		if(a[i]>0)
		{
			if(s[i]>large)
			{
				large=s[i];
				r=i;
			}
		}
}
if(large==56)
{
large=8; 
} 

 else if(large==57)
{
large=9; 
} 
 
  else if(large==55)
{
large=7; 
} 

 else if(large==54)
{
large=6; 
} 

 else if(large==53)
{
large=5; 
} 

 else if(large==52)
{
large=4; 
} 

  else if(large==51)
{
large=3; 
} 

 else if(large==50)
{
large=2; 
} 

 else if(large==49)
{
large=1; 
} 

if(large==48)
{
large=0; 
} 

	a[r]=0;	
	cout<<large;
large=0;
}
}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
