#include<bits/stdc++.h>
#define N 100005
#define M 100005
#define int long long
using namespace std;
int n,m,a[N],s[N],mis=111,mia=10000000,sl,al;
signed main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		mis=min(mis,s[i]);
		if(s[i]=='0')sl++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mia=min(mia,a[i]);
		if(a[i]=='0')al++;
	}
	if(m==n)
	{
		if(mis==0||mia==0)cout<<0;
		else
		{
			int sum=1;
			for(int i=1;i<=n;i++)
			{
				sum*=i;
				sum%=998244353;
			}
			cout<<sum;
		}
		return 0;
	}
	if(m>(n-max(al,sl)))
	{
		cout<<0;
		return 0;
	}
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
