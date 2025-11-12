#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,x,y,c,ans=LLONG_MAX;
int a[10005][10005];
ll b[15][10005];
bool f[10005];
bool f1[15];
void dfs(ll kl,ll sum)
{
	if(sum>=ans)return;
	bool fsf=0;
	f[kl]=1;
	for(ll i=1;i<=n;i++)
	{
		if(!f[i])
		{
			if(a[i][kl]<INT_MAX)dfs(i,sum+a[i][kl]);
			else
			{
				for(ll j=1;j<=k;j++)
				{
					if(!f1[j])
					{
						f1[j]=1;
						dfs(i,sum+b[j][kl]+b[j][0]+b[j][i]);
						f1[j]=0;
					}
					else
					{
						dfs(i,sum+b[j][kl]+b[j][i]);
					}
				}
			}
			fsf=1;
		}
	}
	if(!fsf)ans=min(ans,sum);
	f1[kl]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			a[i][j]=INT_MAX;
		}
	}
	
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=min(a[x][y]*1ll,c);
		a[y][x]=max(a[x][y]*1ll,c);
	}
	for(ll i=1;i<=k;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}  
