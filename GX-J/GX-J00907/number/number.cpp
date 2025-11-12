#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
char s;
int a[10000001],ans=0,i=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		i++;
		if(s=='0')
		  a[i]=0;
		else
		if(s=='1')
		  a[i]=1;
		else
		if(s=='2')
		  a[i]=2;
		else
		if(s=='3')
		  a[i]=3;
		else
		if(s=='4')
		  a[i]=4;
		else
		if(s=='5')
		  a[i]=5;
		else
		if(s=='6')
		  a[i]=6;
		else
		if(s=='7')
		  a[i]=7;
		else
		if(s=='8')
		  a[i]=8;
		else
		if(s=='9')
		  a[i]=9;
		else
		  a[i]=10;
	}
	for(int x=9;x>=0;x--)
	{
	  for(int j=1;j<=i;j++)
	  {
	    if(a[j]==x)
	      cout<<a[j];
	  }
	}
	return 0;
}
 
