#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int main()
{
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	long long t=1,d,n=0,c[n],s[n];
	for(int i=1;i<=1;i++)
	{
		cin>>s[i];
		n++;
	}
	for(int i=1;i<=1;i++)
	{
		if(s[i]=='1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9' || '0')
		{
			c[t]=s[i];
			t++;
		}
		if(t>n)
		{
			t--;
			break;
		}
	}
	for(int i=1;i<=t;i++)
	{
		for(int j=t;j>=1;j--)
		{
			d=0;
			if(c[i]<=c[j])
			{
				d=c[j];
				c[j]=c[i];
				c[i]=d;
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<c[i];
	}
	return 0;
}
