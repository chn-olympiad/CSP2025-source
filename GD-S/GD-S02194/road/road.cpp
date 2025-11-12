#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e4+10,M=1.7e6+10;
struct node{int x,y;LL c;}e[M];int len;
bool cmp(node n1,node n2){return n1.c<n2.c;}
int fa[N],a[20];
int findfa(int x){return fa[x]==x?fa[x]:fa[x]=findfa(fa[x]);}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,k;cin>>n>>m>>k;len=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;LL w;
		cin>>x>>y>>w;
		len++;e[len]={x,y,w};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			LL x;cin>>x;
			len++;e[len]={n+i,j,x};
		}
	}
	sort(e+1,e+len+1,cmp);
	for(int i=1;i<=n+k+1;i++)fa[i]=i;
	LL ans=0;int sum=0;
	for(int i=1;i<=len;i++)
	{
		int tx=findfa(e[i].x),ty=findfa(e[i].y);
		if(tx!=ty)
		{
			fa[tx]=ty;
			sum++;ans+=e[i].c;
			if(sum==n+k-1)break;
		}
	}
	cout<<ans;
	return 0;
}
