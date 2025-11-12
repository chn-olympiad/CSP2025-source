#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int n,ans;
int a[N];
bool vis[N];
void dfs(int k)
{
	if(k>n)
	{
		int max_ai=0,sum_ai=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				max_ai=max(max_ai,a[i]);
				sum_ai+=a[i];
			}
		}
		if(sum_ai>max_ai*2)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	vis[k]=1;
	dfs(k+1);
	vis[k]=0;
	dfs(k+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1);
	ans%=mod;
	printf("%d",ans);
	return 0;
}

