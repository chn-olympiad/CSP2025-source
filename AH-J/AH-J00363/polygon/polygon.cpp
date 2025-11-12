#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e3+10,MOD=998244353;
LL a[N],n,cnt=0,t[N][N];
bool check(LL sum,LL maxn)
{
	if(sum>maxn*2)return true;
	return false;
}
void dfs(LL cur,LL sum,LL num,LL maxn,LL psum,LL pmaxn)
{
	if(num>=3&&check(sum,maxn))
	{
		if(pmaxn==maxn&&psum==sum)return ;
		cnt=(cnt%MOD+1%MOD)%MOD;
	}
	if(cur>n)return ;
	dfs(cur+1,sum+a[cur],num+1,max(maxn,a[cur]),sum,maxn);
	dfs(cur+1,sum,num,maxn,sum,maxn);	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(1,0,0,0,0,0);
	printf("%lld",cnt%MOD);
	return 0;
}
