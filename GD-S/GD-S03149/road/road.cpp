#include<bits/stdc++.h>
#define int long long
#define For(i,x,y) for(int i = x;i <= y;i ++ )
#define For_(i,x,y) for(int i = x;i >= y;i --)
#define fs first
#define sc second
#define y0 y0_
#define y1 y1_
#define yn yn_
#define j0 j0_
#define j1 j1_
#define jn jn_
#define pii pair<int,int> 
#define pb push_back
using namespace std;
const int N = 2e5 + 5,M = 1e6+5;
const int mod = 998244353;
vector<int> mp[N];
int n,m,k;
struct node{
	int u,v,w;
}edge[M];

int f[N];
int c[15][N];
int ans;
int initans = 0;
int find(int x){
	return f[x] == x ? x:f[x] = (find(f[x]));
}vector<node> v;
bool cmp(node a,node b) {
	return a.w < b.w;
}
void init(){// init kruskal
	sort(edge + 1,edge + 1 + m,cmp);
	For(i,1,n) f[i] = i;
	int cnt = 0;
	For(i,1,m){
		if(find(edge[i].u) != find(edge[i].v)){
			initans += edge[i].w;
			cnt ++;
			f[find(edge[i].u)] = find(edge[i].v);
			v.pb(edge[i]);
		}
		if(cnt == n) break;
	}
	ans = initans;
}
void kruskal(int z){
	vector<node> nw;
	for(node it:v) nw.pb(it);
	int cost = 0;
	int cnt = 0;
	For(i,1,k) if((z>>(i-1)) & 1){
		++cnt;
		cost += c[i][0];
		For(j,1,n) nw.pb({n + cnt,j,c[i][j]});
	}sort(nw.begin(),nw.end(),cmp);
	
	For(i,1,n + cnt) f[i] = i;
	int val = 0;
	for(auto it : nw){
		if(find(it.u) != find(it.v)){
			f[find(it.u)] = find(it.v);
			val += it.w;
		}
	}
	ans = min(ans,val + cost); 
} 
void solve(){
	ans = 1e18;
	cin >> n >> m >> k;
	For(i,1,m){
		scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	For(i,1,k) {
		For(j,0,n) cin >> c[i][j];
	}
	init();
//	cout << initans<< endl;
	For(z,0,(1ll<<k) - 1) kruskal(z);
	cout << ans << endl;
	
} signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
//	cin >> T;
	while(T--){
		solve();
	}return 0;
}

/*

4 4 2 
1 4 6 
2 3 7 
4 2 5 
4 3 4 
1 1 8 2 4  
100 1 3 2 4 

*/
