#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int s[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(m==n&&s[i]==0)
		{
			cout<<0;
			return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]=='0')
		{
			return 0;
		}
	}
	long long p=1;
	for(int i=1;i<=n;i++)
	{
		p=p%998244353*i;
	}
	cout<<p;
}
