#include<bits/stdc++.h>
#define int long long
using namespace std;

int n , m , k , fa[10005] , maxc , ans = 1e18 , q;
struct node{
	int u , v , w;
} E[10000005];
struct Node{
	int c;
	int a[10005];
} p[15];
bool cmp(node x , node y){
	return x.w < y.w;
}
int find(int x){
	if( fa[x] == x ) return x;
	return fa[x] = find(fa[x]);
}
signed main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for( int i = 1 ; i <= m ; i++ ){
		cin >> E[i].u >> E[i].v >> E[i].w;
	}
	if( !k ){
		int ans = 0;
		sort(E + 1 , E + m + 1 , cmp);
		for( int i = 1 ; i <= n ; i++ ) fa[i] = i;
		for( int i = 1 ; i <= m ; i++ ){
			if( find(E[i].u) == find(E[i].v) ) continue;
			fa[find(E[i].u)] = find(E[i].v);
			ans += E[i].w;
		}
		cout << ans << "\n";
		return 0;
	}
	for( int i = 1 ; i <= k ; i++ ){
		cin >> p[i].c;
		maxc = max( maxc , p[i].c );
		for( int j = 1 ; j <= n ; j++ ) cin >> p[i].a[j];
	}
	for( int i = 0 ; i < ( 1 << k ) ; i++ ){
		int answ = 0 , now = m;
		for( int j = 1 ; j <= k ; j++ ){
			if( !(i & ( 1 << j - 1 )) ) continue;
			answ += p[j].c;
			for( int q = 1 ; q <= n ; q++ ){
				for( int l = q + 1 ; l <= n ; l++ ){
					if( q == l ) continue;
					E[++now] = {q , l , p[j].a[q] + p[j].a[l]};
				}
			}
		}
		//2^k * k * n^2 * log(k * n^2)
		sort(E + 1 , E + now + 1 , cmp);
		for( int j = 1 ; j <= n ; j++ ) fa[j] = j;
		for( int j = 1 ; j <= min( n * n , now ) ; j++ ){
			if( find(E[j].u) == find(E[j].v) ) continue;
			fa[find(E[j].u)] = find(E[j].v);
			answ += E[j].w;
		}
		ans = min( ans , answ );
	}
	cout << ans;
	return 0;
} 
