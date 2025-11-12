#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
char b[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long s1=s.length(),w=0,q=0,qq=1;
	for(long long i=0;i<s1;i++)
	{	if(s[i]=='0')
		{
			a[w]=0;
			w++;
		}
		if(s[i]=='1')
		{
			a[w]=1;
			w++;
		}
		if(s[i]=='2')
		{
			a[w]=2;
			w++;
		}
		if(s[i]=='3')
		{
			a[w]=3;
			w++;
		}
		if(s[i]=='4')
		{
			a[w]=4;
			w++;
		}
		if(s[i]=='5')
		{
			a[w]=5;
			w++;
		}
		if(s[i]=='6')
		{
			a[w]=6;
			w++;
		}
		if(s[i]=='7')
		{
			a[w]=7;
			w++;
		}
		if(s[i]=='8')
		{
			a[w]=8;
			w++;
		}
		if(s[i]=='9')
		{
			a[w]=9;
			w++;
		}	
	}
	for(long long i=0;i<w;i++)
	{	long long t=a[i];
		qq=1;
		for(int j=i+1;j<=w;j++)
		{
			if(t<a[j]&&i!=w-1)
			{
				t=a[j];
				a[j]=-111;
				i--;
				qq=0;
			}
		}
		if(qq!=0&&i!=w-1)
		{
			a[i]=-111;
		}
		if(t==0)
		{
			b[q]='0';
			q++;
		}
		if(t==1)
		{
			b[q]='1';
			q++;
		}
		if(t==2)
		{
			b[q]='2';
			q++;
		}
		if(t==3)
		{
			b[q]='3';
			q++;
		}
		if(t==4)
		{
			b[q]='4';
			q++;
		}if(t==5)
		{
			b[q]='5';
			q++;
		}if(t==6)
		{
			b[q]='6';
			q++;
		}if(t==7)
		{
			b[q]='7';
			q++;
		}if(t==8)
		{
			b[q]='8';
			q++;
		}if(t==9)
		{
			b[q]='9';
			q++;
		}
		
	}
	for(long long i=0;i<q;i++)
	{
		cout<<b[i];
	}
	return 0;
}
