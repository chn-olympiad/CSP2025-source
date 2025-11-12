#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , m , k , x , y , z , tot , b[10005] , g[1005][1005] , ans , cnt = 1 , dis[10005] , l[10005] , r[10005] ;
bool f[10005] ;
void link(int x,int y)
{
	r[x]=y;
	l[y]=x;
}
void del(int x){link(l[x],r[x]);}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	memset(dis,0x3f,sizeof(dis));
	memset(g,0x3f,sizeof(g));
	cin >> n >> m >> k ;
	for ( int i = 0 ; i <= n ; i ++ )link(i,i+1);
	while (m--)
	{
		cin >> x >> y >> z ;
		g[y][x]=g[x][y]=min(g[x][y],z);
	}
	while (k--)
	{
		cin >> x ;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			cin >> b[i] ;
			for ( int j = 1 ; j < i ; j ++ )g[i][j]=g[j][i]=min(g[i][j],x+b[i]+b[j]);
		}
	}
	dis[1]=0;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		int l = 0 ;
		for ( int j = r[0] ; j <= n ; j = r[j] )if (dis[j]<dis[l])l=j;
		del(l);
		ans+=dis[l];
		for ( int j = r[0] ; j <= n ; j = r[j] )dis[j]=min(dis[j],g[l][j]);
	}
	cout << ans ;
	return 0;
}
