#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,f[10000005],val[15],vis[10000005],p;
long long ansx,ansy;
struct node
{
	int u,v,k;
}road[15000005];
int find(int x){return f[x]==0?x:f[x]=find(f[x]);}
bool cmp(node x,node y){return x.k<y.k;}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);p=n;if(k==0) ansy=INT_MAX;
	for(int i=1,a,b,c;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		road[++cnt].k=c;road[cnt].u=a;road[cnt].v=b;
	}
	sort(road+1,road+1+cnt,cmp);
	for(int i=1;i<p;i++)
	{
		int xx=find(road[i].u),yy=find(road[i].v);
		if(xx!=yy)
		{
			ansx+=road[i].k;
			f[xx]=yy;
		}
		else p++;
	} 
	if(k!=0)
	{
		memset(f,0,sizeof(f));
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&val[i]);
			for(int j=1,b;j<=n;j++)
			{
				scanf("%d",&b);
				road[++cnt].k=b+val[i];road[cnt].u=i+m;road[cnt].v=j;
			}
		}
		sort(road+1,road+1+cnt,cmp);p=n;
		for(int i=1;i<=p;i++)
		{
			if(road[i].u>m&&vis[road[i].u-m]) road[i].k-=val[road[i].u-m];
			int xx=find(road[i].u),yy=find(road[i].v);
			if(xx!=yy)
			{
				if(road[i].u>m) vis[road[i].u-m]=1;
				ansy+=road[i].k;
				f[xx]=yy;
			}
			else p++;
		} 
	}
	printf("%lld",min(ansx,ansy));
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
6 8 0
1 2 2
1 3 5
1 4 3
1 6 3
2 3 7
2 5 4
4 6 2
3 5 1
*/
