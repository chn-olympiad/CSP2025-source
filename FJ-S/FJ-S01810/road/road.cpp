#include<bits/stdc++.h>
#define N 10010
#define ll long long
using namespace std;
int n,m,k,c[15],a[15][N];
struct node
{
	int u,v,w;
}e[1000010],edge[N],newe[N*10+N+N],kedge[11][N];
int par[N+10];
int find(int x)
{
	if(x!=par[x]) par[x]=find(par[x]);
	return par[x];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			kedge[i][j]={n+i,j,a[i][j]};
		}
		sort(kedge[i]+1,kedge[i]+1+n,[&](node X,node Y){return X.w<Y.w;});
	}
	for(int i=1;i<=n+k;i++)
	{
		par[i]=i;
	}
	
	
	sort(e+1,e+1+m,[&](node X,node Y){return X.w<Y.w;});
	ll ans=0;
	int tmp=0;
	for(int i=1;i<=m;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v)
		{
			par[u]=v;
			ans+=e[i].w;
			edge[++tmp]=e[i];
//			cout<<e[i].w<<" ";
		}
	}
//	cout<<endl;
	if(k==0)
	{
		printf("%lld",ans);
		return 0;
	}
	
	
	
	int tot;
	for(int S=1;S<(1<<k);S++)
	{
		ll res=0;
		int cnttt=0;
		for(int i=1;i<=n+k;i++)
		{
			par[i]=i;
		}
		int idx[11]={1,1,1,1,1,1,1,1,1,1,1};
		for(int j=0;j<k;j++)
		{
			if(((1<<j)&S)==0) continue; 
			res+=c[j+1];
			cnttt++;
//			cout<<j+1<<"-";
		}
//		cout<<endl;
//		cout<<endl<<S<<endl;;
		
		for(int i=1;i<=n-1+n*cnttt;i++)
		{
			int min=0x3f3f3f3f,pos,u,v;
			
			for(int j=0;j<k;j++)
			{
				if(((1<<j)&S)==0) continue;
//				cout<<j<<" ";
				if(idx[j+1]<=n&&kedge[j+1][idx[j+1]].w<min)
				{
					min=kedge[j+1][idx[j+1]].w;
					u=kedge[j+1][idx[j+1]].u;
					v=kedge[j+1][idx[j+1]].v;
					pos=j+1;
				}
			}
			if(idx[0]<=n-1&&edge[idx[0]].w<min)
			{
				min=edge[idx[0]].w;
				u=edge[idx[0]].u;
				v=edge[idx[0]].v;
				pos=0;
			}
			idx[pos]++;
			u=find(u),v=find(v);
			
			if(u!=v)
			{
				res+=min;
				par[u]=v;
//				cout<<u<<","<<v<<","<<min<<" ";
			}
		}
//		cout<<endl<<res<<endl;;
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}