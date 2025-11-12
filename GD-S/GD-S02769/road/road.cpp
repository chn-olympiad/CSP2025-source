#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 7;
int n,m,k;
vector<pair<int,int>> E[N],V[N];
int cnt = 0,cnt1 = 0;
int mini = 9909090909657657;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		E[u].push_back({v,w});
		E[v].push_back({u,w});
		cnt += w;
	}
	mini = min(cnt,mini);
	for(int i = 1; i <= k; i++){
		cnt = 0;
		for(int j = 1; j <= m - 1; j++){
			int x;
			cin >> x;
			cnt += x;
		}
		mini = min(cnt,mini);
	}
	cout << mini;
}
