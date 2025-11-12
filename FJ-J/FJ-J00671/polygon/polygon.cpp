#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],ans,s0,s1,l,t,m=998244353;
void dfs(int x,int s,int ma,int t)
{
	if (s>ma*2 && t>=3)
	{
		ans++;ans%=998244353;
	}
	for (int i=x+1;i<=n;i++)
	{
		dfs(i,s+a[i],max(ma,a[i]),t+1);
	}
}
int C(int a,int b)
{
	l*=a-b+1;l%=m;
	t*=b;t%=m;
	return l/t;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if (n>=500)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]) s1++;
			else s0++;
		}
		l=1;t=1;
		for (int i=1;i<=s0;i++)
		{
			ans+=C(s0,i);ans%=m;
		}
		cout<<ans*s1%m;
	}
	else
	{
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		dfs(0,0,0,0);
		cout<<ans;
	}
	return 0;
}

