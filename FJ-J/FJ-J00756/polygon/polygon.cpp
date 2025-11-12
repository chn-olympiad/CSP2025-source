#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n,cnt,sum,f;
int a[5005],vis[5005];
long long ans[5005];
void dfs(int k)
{
	if(k > n)
	{
		cnt=sum=0;
		for(int i=1; i<=n; i++)
		{
			if(vis[i] == 1)
			{
				ans[++cnt]=a[i];
				sum+=a[i];
			}
		}
		
		sort(ans+1,ans+1+cnt);
		if(sum > 2*ans[cnt])
			f=(f+1)%MOD;
			
		return ;
	}
	
	for(int i=0; i<=1; i++)
	{
		vis[k]=i;
		dfs(k+1);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;	
	for(int i=1; i<=n; i++)
		cin>>a[i];
		
	dfs(1);
	cout<<f%MOD;
	
	return 0;
}
