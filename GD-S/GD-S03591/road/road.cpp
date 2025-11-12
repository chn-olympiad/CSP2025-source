#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
#define pii pair<int,ll>
const int N = 1e4+3;
vector<vector<pii>> e(N);
int n, m,k,u,v,in[N] = {},maxn = 0,s = 1,c[12][N], vis[N];
ll cot,w;
queue<int> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	FOR(i,1,m){
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		in[u]++;
		in[v]++;
		if(in[u] > maxn){
			maxn = in[u];
			s = u;
		}
		if(in[v] > maxn){
			maxn = in[v];
			s = v;
		}
		cot += w;
	}
	FOR(i,1,k){
		cin >> c[i][1];
		FOR(j,2,n+1)cin >> c[i][j];
	}
	int f = 0;
	int in1[N];
	ll cost;
	FOR(i,1,k){
		q.push(s);
		vis[s]++;
		f = 0;
		FOR(i,1,n)in1[i] = in[i];
		for(auto [v,w] : e[s]){
			if(vis[v] == i)continue;
			in1[s]--;
			q.push(v);
			vis[v]++;
			cost = c[i][v]+c[i][u];
			if(cost < w){
				f = 1;
				cot = cot-w+cost;
				w = cost;
			}
			if(in1[s] == 0){
				s = q.front();
				q.pop();
			}
		}
		if(f == 1)cot+=c[i][1];
	}
	cout << cot;
	return 0;
}
