#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10,M=2e6+10,K=15;
struct node{
	int u,v,w;
}b[M];
int n,m,k,u,v,w,id,ans,minn,fa[N],c[K],a[K][N],dis[N][N];
bool vis[M],used[K];
vector<node>g[N];
bool cmp( node a , node b )  {  return a.w<b.w;  }
int find( int x )
{
	if( fa[x]==x )  return fa[x];
	else  return fa[x]=find( fa[x] );
}
void tree()
{
	for( int i=1 ; i<=m ; i++ )
	{
		u=b[i].u,v=b[i].v,w=b[i].w;
		u=find(u),v=find(v);
		if( u==v )  continue;
		fa[u]=v,vis[i]=true,ans+=w;
	}
	return ;
}
signed main()
{
	freopen( "road.in" , "r" , stdin );
	freopen( "road.out" , "w" , stdout );
	cin>>n>>m>>k;
	memset( dis , 0x3f , sizeof(dis) );
	for( int i=1 ; i<=n ; i++ )  fa[i]=i;
	for( int i=1 ; i<=m ; i++ )
	{
		cin>>u>>v>>w;
		if( u>v )  swap( u , v );
		dis[u][v]=min( dis[u][v] , w );
		b[i]=(node){ u , v , w };
	}
	for( int i=1 ; i<=k ; i++ )
	{
		cin>>c[i];
		for( int j=1 ; j<=n ; j++ )
			cin>>a[i][j];
	}
	if( k==0 )
	{
		sort( b+1 , b+1+m , cmp ),tree();
		cout<<ans<<endl;
		return 0;
	}
	for( int i=1 ; i<=n ; i++ )
	{
		for( int j=i+1 ; j<=n ; j++ )
		{
			minn=1e18,id=0;
			for( int t=1 ; t<=k ; t++ )
			{
				if( a[t][i]+a[t][j]<minn )
					minn=a[t][i]+a[t][j],id=t;
			}
			if( minn<dis[i][j] )
			{
				dis[i][j]=minn;
				b[++m]=(node){ i , j , dis[i][j] };
			}
		}
	}
	sort( b+1 , b+1+m , cmp );
	tree();
	cout<<ans<<endl;
//	for( int i=1 ; i<=m ; i++ )
//	{
//		if( !vis[i] )  continue;
//		u=b[i].u,v=b[i].v,w=b[i].w;
//		minn=1e18,id=0;
//		for( int j=1 ; j<=k ; j++ )
//		{
//			if( a[j][u]+a[j][v]+(!used[j])*c[j]<minn )
//				minn=a[j][u]+a[j][v]+(!used[j])*c[j],id=j;
//		}
//		if( minn<w )  ans=ans-w+minn,used[id]=true;
//	}
//	cout<<ans<<endl;
	return 0;
}
