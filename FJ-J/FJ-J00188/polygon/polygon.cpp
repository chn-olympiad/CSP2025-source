#include <bits/stdc++.h>
using namespace std;

const int N=5000+5,MOD=998244353;

int a[N],n,cnt,maxa;
long long ans;

void dfs(int k)
{
	if (k>n)
	{
		if (cnt>maxa*2)
		{
			ans=(ans+1)%MOD;
		}
		return;
	}
	int maxb=maxa;
	cnt+=a[k];
	maxa=a[k];
	dfs(k+1);
	cnt-=a[k];
	maxa=maxb;
	dfs(k+1);
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}
