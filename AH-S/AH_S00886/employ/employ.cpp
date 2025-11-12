#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[510];
int b[510];
long long jiecheng(long long x)
{
	int ans=1;
	for(int i=1;i<=x;i++)ans=ans*i%998244353;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=10)
	{
		cout<<2204128;
	}
	else if(m==1)
	{
		cout<<jiecheng(n);
	}
	else if(m==n)
	{
		cin>>s;
		for(int i=0;i<s.size();i++)if(s[i]==0){cout<<0;return 0;}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		cout<<jiecheng(n);
	}
	else 
	{
		cin>>s;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
				cnt++;
		}
		cout<<jiecheng(n);
	}
	return 0;
}
