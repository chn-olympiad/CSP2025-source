#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,K=11;
int n,m,k,p[N],sz[N],c[K],val[K][N],tot;
long long ans=1e18;
struct edge{
	int x,y,z,o;
}a[100*N],b[100*N];
bool cmp(edge s,edge t){return s.z<t.z;}
int getfa(int x)
{
	if(p[x]==x)return x;
	return p[x]=getfa(p[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>val[i][j];
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++)
	{
		int fx=getfa(a[i].x),fy=getfa(a[i].y);
		if(fx!=fy)
		{
			if(sz[fx]<sz[fy])swap(fx,fy);
			p[fy]=fx,sz[fx]+=sz[fy];
			b[++tot]=(edge){a[i].x,a[i].y,a[i].z,0};
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)b[++tot]=(edge){i+n,j,val[i][j],i};
	}
	sort(b+1,b+tot+1,cmp);
	for(int i=0;i<(1<<k);i++)
	{
		long long res=0;
		for(int j=0;j<k;j++)if(i&(1<<j))res+=c[j+1];
		for(int j=1;j<=n+k;j++)p[j]=j,sz[j]=1;
		for(int j=1;j<=tot;j++)if(!b[j].o||(i&(1<<(b[j].o-1))))
		{
			int fx=getfa(b[j].x),fy=getfa(b[j].y);
			if(fx!=fy)
			{
				if(sz[fx]<sz[fy])swap(fx,fy);
				p[fy]=fx,sz[fx]+=sz[fy],res+=b[j].z;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}

