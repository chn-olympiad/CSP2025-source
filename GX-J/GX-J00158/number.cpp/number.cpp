#include<bits/stdc++.h>
using namespace std;
long long n[1000005],t,a,d;
string s;
int main( )
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	while(1)
	{
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=t;j++)
			{
				if(s[i]>s[j])
				{
					s[i]=s[1];
				}
			}
		}
		cout<<s;
		return 0;
	}
	for(int i=0;i<=t;i++)
	{
		if(s[i]>9 && s[i]<0)
		{
			a++;
		}
		if(s[i]<=9 && s[i]>=0)
		{
			n[i]=s[i];
		}
		for(int j=1;j<=t;j++)
		{
			if(n[i]>=n[j])
			{
				n[i]=n[j-1];
				n[j]=n[i+1];
			}
			for(int k=s[a];k<=t;k++)
			{
				cout<<n[i]<<n[j];
				return 0;
			}
		}
	}
	for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=t;j++)
			{
				cout<<max(s[i],s[j])<<min(s[i],s[j]);
			}
		}
	return 0;
}
