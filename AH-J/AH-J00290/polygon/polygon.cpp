#include<bits/stdc++.h>
using namespace std;
long long a[5005],vis[5005],ans[5005],n,k,stn,sum,cnt,ansc;

void dfs(long long k,long long c,long long maxn)
{
	if(k==0){if(maxn*2<sum)cnt++;return;}
	for(int j=c;j<=n;j++)
	{
		maxn=max(maxn,a[j]);
		ans[stn-k+1]=a[j];
		sum+=a[j];
		dfs(k-1,j+1,maxn);
		sum-=a[j];
		ans[stn-k+1]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
    for(long long i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(long long i=3;i<=n;i++)
	{
		stn=i;
		dfs(i,1,0);
		sum=0;
		ansc+=cnt;
		ansc%=998244353;
		cnt=0;
	}
	cout<<ansc;
	return 0;
}



