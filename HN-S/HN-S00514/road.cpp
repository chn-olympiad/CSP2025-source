#include <bits/stdc++.h>
using namespace std ;

struct node
{
	int sv , sw ;
};

int n , m , k , u , v , w , cnt , ans ;
bool f[10004] ;
vector <int> V[10004] ;
vector <int> W[10004] ;
vector <node> s ;

bool cmp( node a , node b )
{
	//cout << a.sv << " " ;
	//if( f[a.sv] ) return 0 ;
	if( a.sw > b.sw ) return 0 ;
	return 1 ;
}

void dfs( int x )
{
	cnt ++ ;
	if( cnt == n ) return ;
	for( int i = 0 ; i < V[x].size() ; i ++ )
	{
		if( !f[V[x][i]] )
		{
			s.push_back({V[x][i],W[x][i]}) ;
		}
	}
	sort( s.begin() , s.end() , cmp ) ;
	int j = 0 ;
	while( f[s[j].sv] )
	{
		s[j].sw = 1e9 ;
		j ++ ;
	}
	//cout << s[0].sv << endl ;
	f[s[j].sv] = 1 ;
	ans += s[j].sw ;
	dfs(s[j].sv) ;
	return ;
} 

int main()
{
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	cin >> n >> m >> k ;
	for( int i = 1 ; i <= m ; i ++ )
	{
		cin >> u >> v >> w ;
		V[i].push_back(v) ;
		W[i].push_back(w) ; 
	}
	f[1] = 1 ;
	dfs(1) ;
	cout << ans ;
	return 0 ;
} 
