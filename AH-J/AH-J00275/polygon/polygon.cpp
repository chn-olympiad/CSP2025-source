#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const long long MOD=998244353;
int n;
int a[MAXN];
long long ans;
void dfs(int cnt,int s,int maxn,int p)
{
	if(p==n)
	{
		return ;
	}
	for(int i=p+1;i<=n;i++)
	{
		int tt=maxn;
		maxn=max(maxn,a[i]);
		if(s>=2&&cnt+a[i]>maxn*2) 
		{
			ans++;
			ans%=MOD;
		}
		dfs(cnt+a[i],s+1,maxn,i);
		maxn=tt;
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(0,0,0,0);
	ans%=MOD;
	printf("%lld",ans);
	return 0;
}
