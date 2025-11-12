#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e4 + 24;
int n,m,k;
int a[24],f[maxn],siz[maxn];
bool flag[24];
struct edge{
	int u,v,w,f;
};
vector<edge> edges;
int find(int x){
	return (f[x] == x ? x : f[x] = find(f[x]));
}
bool merge(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y){
		return false;
	} 
	f[x] = y;
	return true;
}
int kelusikaer(int now){
	int ans = 0,cnt = 0;
	for(int i = 1;i <= n + k;i++){
		f[i] = i;
		siz[i] = 1;
	}
	for(auto i : edges){
		if(flag[i.f]){
			if(merge(i.u,i.v)){
				ans += i.w;
				cnt++;
				if(cnt == n + now - 1){
					return ans;
				}
			}
		}
	}
	return 1e18;
}
bool cmp(edge a,edge b){
	return a.w < b.w;
}
int dfs(int x,int sum,int cnt){
	flag[x] = 1;
	int ans = kelusikaer(cnt) + sum;
	for(int i = x + 1;i <= k;i++){
		ans = min(ans,dfs(i,sum + a[i],cnt + 1));	
	}
	flag[x] = 0;
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> m >> k;
	flag[0] = 1;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edges.push_back({u,v,w,0});
//		edge a = edges[edges.size() - 1];
//		cout << a.u << " " << a.v << " " << a.w << " " << a.f << endl;
	} 
	for(int i = 1;i <= k;i++){
		cin >> a[i];
		for(int j = 1;j <= n;j++){
			int w;
			cin >> w;
			edges.push_back({n + i,j,w,i});
//			edge a = edges[edges.size() - 1];
//			cout << a.u << " " << a.v << " " << a.w << " " << a.f << endl;
		} 
	}
	sort(edges.begin(),edges.end(),cmp);
//	cout << "CJY" << endl;
	int ans = kelusikaer(0);
//	cout << "CJY" << endl;
	for(int i = 1;i <= k;i++){
		ans = min(ans,dfs(i,a[i],1));
	}
	cout << ans;
	return 0;
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
