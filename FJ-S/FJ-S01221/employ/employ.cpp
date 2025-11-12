#include<bits/stdc++.h>
using namespace std;
char s[505];
long long sum=0;
int c[505];
long long solve(int a)
{
	long long num=1;
	for(int i=a;i>=1;i--)
	{
		num=num*i;
	}
	return num;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				sum++;
			}
		}
		cout<<(solve(sum)/solve((n-1)))%998244353;
		return 0;
	}
	if(n==m)
	{
		int i=1;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				cout<<0;
				return 0;
			}
		}
		sum=solve(n);
		return 0;
	}
	for(int i=m;i<=n;i++)
	{
		sum+=solve(n)/solve(m)/solve(n-m);
	}
	cout<<sum%998244353;
	return 0;
}
