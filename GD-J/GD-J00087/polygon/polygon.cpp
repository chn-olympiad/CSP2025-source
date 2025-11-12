#include<bits/stdc++.h>
using namespace std;
long long n,m[5001],sum,ans,f[5001];
void dfs(long long wz,long long sum,long long gs,long long ma)
{
	if(sum>ma*2&&gs>=3) ans=(ans+1)%998224353;
	for(long long i=wz+1;i<=n;i++)
	{
		dfs(i,sum+m[i],gs+1,max(ma,m[i]));
	}
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>m[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
//1s 512Mib n<=3/10/20/500/5000 ai<=10/100/1/5000
//最大：n*n 
//预计得分：24 

