#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,c[12],a[12][N],lu[N][N];
long long ans=LONG_LONG_MAX,ans1=0;
bool p[N];
queue<int> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		lu[u][v]=w;
		lu[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			p[i]=true;
			q.push(i);
			ans1=0;
			while(!q.empty())
			{
				int now=q.front();
				for(int j=1;j<=n;j++)
				{
					if(p[j]==false&&lu[now][j]!=0)
					{
						p[j]=true;
						q.push(j);
						ans1+=lu[j][now];
					}
				}
				q.pop();
			}
			for(int j=1;j<=n;j++)
			{
				p[i]=false;
			}
			ans=min(ans,ans1);
		}
		cout<<ans;
	}
	return 0;
 } 
