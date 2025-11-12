#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 25;
struct edge{
	int u,v,w;
	
	bool operator>(const edge b) const {
		return w > b.w;
	}
};
int f[N];
int n,m,k;
int c[13],a[N][13],mi[13],minn[13];
int bac[13];
priority_queue<edge,vector<edge>,greater<edge>> q,q2,road[13];
int find(int x){
	return (f[x] == x) ? (x) : (f[x] = find(f[x])); 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(minn,0x3f,sizeof(minn));
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) f[i] = i;
	for(int i = 1,u,v,w;i <= m;i++){
		cin >> u >> v >> w;
		q.push({u,v,w});
	}
	for(int j = 1;j <= k;j++){
		cin >> c[j];
		a[0][j] = 1e18;
		for(int i = 1;i <= n;i++){
			cin >> a[i][j];
			if(a[mi[j]][j] > a[i][j]) mi[j] = i;
		}
	}
	int ans = 0;
	while(!q.empty()){
		edge s = q.top(); q.pop();
		if(find(s.u) == find(s.v)) continue;
		ans += s.w;
		road[0].push(s);
		f[find(s.v)] = find(s.u);
	}
	bac[0] = 0;
	for(int i = 1;i <= k;i++){
		int t = mi[i];
		for(int j = 0;j < i;j++){
			int res = bac[j] + c[i] + a[t][i];
			q = road[j];
			for(int l = 1;l <= n;l++) f[l] = l;
			for(int l = 1;l <= n;l++)
				if(l != t) q.push({t,l,a[l][i]});
			while(!q.empty()){
				edge s = q.top(); q.pop();
				if(find(s.u) == find(s.v)) continue;
				res += s.w;
				q2.push(s);
				f[find(s.v)] = find(s.u);
			}
			if(res < minn[i]){
				minn[i] = res;
				road[i] = q2;
				bac[i] = bac[j] + c[i] + a[t][i];
			}
			while(!q2.empty()) q2.pop();
		}
		ans = min(ans,minn[i]);
	}
	cout << ans;
	return 0;
} 
