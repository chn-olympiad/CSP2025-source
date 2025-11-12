#include<bits/stdc++.h>
using namespace std;
int a[505];
int N=998244353;
int n,m;
string s;
int c=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0)
			c++;
	}	
	bool f=1;
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='1')
			f=0;
		if(s[i]=='1'&&x==0)
			x=(i+1);
	}	
	long long sum=0;
	if(f==1)
	{
		sum=1;
		if(c<m)
		{
			cout<<0;
			return 0;
		}
		for(int i=1;i<=c;i++)
		{
			sum*=i;
			sum%=N;
		}
		cout<<sum;
		return 0;
	}
	if(m==1)
	{
		long long y=1;
		for(int i=1;i<n;i++)
		{
			y*=i;
			y%=N;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>x)
			{
				sum+=y;
				sum%=N;
			}
		} 
		cout<<sum;
		return 0;
	}
	if(m==n)
	{
		if(f==0||c!=0)
		{
			cout<<0;
			return 0;
		}
		sum=1;
		for(int i=1;i<=n;i++)
		{
			sum*=i;
			sum%=N;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
