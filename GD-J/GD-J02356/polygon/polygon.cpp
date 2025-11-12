#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int mod=998244353;
int a[N];
int s[N];
int n;
int ans;
void dfs(int x,int maxx,int sum,int cnt)
{
	if(x==n+1)
	{
		if(sum>maxx*2) ans++;
		return;
	}
	if(cnt+n-x<2||sum+s[n]-s[x-1]<=2*maxx) return;
	int t=sum,tmax=maxx;
	dfs(x+1,tmax,t,cnt);
	maxx=max(maxx,a[x]),sum+=a[x];
	dfs(x+1,maxx,sum,cnt+1);
	maxx=tmax,sum=t;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	dfs(1,0,0,0);
	cout<<ans%mod;
	return 0;
}
