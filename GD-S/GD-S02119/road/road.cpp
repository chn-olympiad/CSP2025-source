#include <bits/stdc++.h>
#define N 1200001
#define rint register int
#define ll long long
using namespace std;
struct Node{
	int u , v;
	ll w;
} edge[N];
int n , m , k , ct;
ll c[12] , ans , res;
int f[10100];

inline int find( int x ){
	if( f[x] != x ) return f[x]=find(f[x]);
	return x;
}

inline void unions( int x , int y ){
	f[x] = y;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	auto read = []( auto &x ){
		char c=getchar();
		while( c<'0' || c>'9' )	c = getchar();
		while( c>='0' && c<='9' ){
			x = x*10 + c-'0';
			c = getchar();
		}
		return;
	};
	
	read(n);	read(m);	read(k);
	
	for( register Node* p=edge+1; p <= edge+m; ++p )	read(p->u),	read(p->v),	read(p->w);
	
	for( rint i=1; i <= k; ++i ){
		read( c[i] );	res += c[i];
		for( register Node* p=edge+m+1; p <= edge+m+n; ++p )
			p->u = i+n , p->v = p-edge-m , read(p->w);
		m += n;
	}
	for( rint i=1; i <= n+k; ++i )	f[i] = i;
	stable_sort( edge+1 , edge+1+m , []( Node a , Node b ){
		return a.w < b.w;
	});
	int r1 , r2;
	for( register Node* p=edge+1; p <= edge+m; ++p ){
		r1 = find(p->u);	r2 = find(p->v);
		if( r1 == r2 )	continue;
		ans += p->w;
		unions( r1 , r2 );
		++ ct;
		if( ct == n+k-1 )	break;
		
	}
	printf("%lld", ans+res );
}
