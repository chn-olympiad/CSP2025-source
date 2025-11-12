#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5005];
const int MOD=998244353;
int f[5005][5005];
int ans=0;
void dfs(int i,int mx,int sum,int tot)
{
	if(i==n+1)
	{
		if(tot>=3&&sum>mx*2)
		{
			ans++;
			ans%=MOD;
		}
		return ;
	}
	dfs(i+1,max(mx,a[i]),sum+a[i],tot+1);
	dfs(i+1,mx,sum,tot);
	return ;
}
signed main()
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
	if(n<=20)
	{
		dfs(1,0,0,0);
		cout<<ans<<"\n";
		return 0;
	}
	for(int r=1;r<=n;r++)
	{
		int k=a[r],id=r,tot=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			f[i][0]=1;
		}
		int pos=0;
		for(int i=1;i<=n;i++)
		{
			if(i==id||a[i]>k)
			{
				continue;
			}
			tot++;
			for(int j=k-1;j>0;j--)
			{
				f[i][j]=f[pos][j];
				if(j>=a[i])
				{
					f[i][j]+=f[pos][j-a[i]];
					f[i][j]%=MOD;
				}
			}
			pos=i;
		}
		//~ cout<<r<<" "<<k<<"\n";
		//~ for(int i=1;i<=n;i++)
		//~ {
			//~ for(int j=0;j<=k;j++)
			//~ {
				//~ cout<<f[i][j]<<" ";
			//~ }
			//~ cout<<"\n";
		//~ }
		//~ cout<<"\n";
		for(int i=0;i<=k-1;i++)
		{
			ans+=f[pos][i];
			ans%=MOD;
		}
		ans-=tot;
	}
	cout<<ans<<"\n";
	return 0;
}
