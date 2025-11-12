#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 3e6 + 5;
int ans;
int n , m , k;
int kw[N];
int fa[N];
int sum;
struct aa{
	int u ;
	int v ;
	int w ;
}edge[N];
int cnt;
bool cmp(aa x , aa y){
	return x.w < y.w ;
}
int getf(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = getf(fa[x]);
}
signed main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0); 
	cin >> n >> m >> k;
	cnt = m;
	for(int i = 1 ;i <= n + k ;i++){
		fa[i] = i;
	}
	for(int i = 1 ;i <= m ;i++){
		int uu , vv , ww;
		cin >> uu >> vv >> ww;
		edge[i] = {uu , vv , ww};
	}
	for(int i = 1 ;i <= k ;i++){
		cin >> kw[i];
		for(int j = 1 ;j <= n ;j++){
			int c;
			cin >> c;
			edge[++cnt] = {n + i , j , c};
		}
	}
	sort(edge + 1 , edge + cnt + 1 , cmp);
	for(int i = 1 ;i <= cnt ;i++){
		aa head = edge[i];
		int fu = getf(head.u );
		int fv = getf(head.v );
		if(fu != fv){
			ans += head.w ;
			fa[fv] = fu;
		}
	}
	cout << ans << endl;
	return 0;
} 
