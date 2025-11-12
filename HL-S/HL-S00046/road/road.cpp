#include<bits/stdc++.h>
using namespace std;
long long int next[1000050],to[1000050],w[1000050],h[1050],c[1000050],u,tot,dc[1050][1050],n,m,k,minn,ans=10000000000;
bool b[1050];
int dfs(int num,int d)
{
	if(num==n)
	{
		ans=min(minn,ans);
	}
	int i=h[d];
	while(i)
	{
		if(!b[to[i]])
		{
			minn+=w[i];
			b[to[i]]=1;
			dfs(num+1,to[i]);
			minn-=w[i];
			b[to[i]]=0;
		}
		i=next[i];
	}
	if(d<=k)
	{
		minn+=c[d];
		for(int j=1;j<=n;j++)
		{
			if(j!=d&&!b[j])
			{
				minn+=dc[d][j];
				b[j]=1;
				dfs(num+1,j);
				minn-=dc[i][j];
				b[j]=0;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(d!=i&&!b[i])
		{
			minn+=c[i];
			minn+=dc[i][d];
			b[i]=1;
			dfs(num+1,to[i]);
			minn-=dc[i][d];
			b[i]=0;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		tot++;
		cin>>u>>to[tot]>>w[tot];
		next[h[u]]=tot;
		h[u]=tot;
		to[to[tot]]=u;
		w[tot+1]=w[tot];
		next[to[tot]]=tot+1;
		h[to[tot]]=tot+1;
		tot++;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>dc[i][j];
	}
	cout<<ans;
	return 0;
 } 
