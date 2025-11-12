#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

using ll = long long;

int n, vis[500005]; ll ans = 0;
bool c[5][N];

struct Node{
	int a, b, c, id;
	int val[4];
} a[N];

vector<pair<int, ll> > e[300300];

ll dp[202][202][202], f[500005]; 

void dfs(int u, int A, int B, int C, ll val){
	if(u == n + 1) return void(ans = max(ans, val));
	if(A <= n / 2) dfs(u+1, A+1, B, C, val + a[u].a);
	if(B <= n / 2) dfs(u+1, A, B+1, C, val + a[u].b);
	if(C <= n / 2) dfs(u+1, A, B, 1+C, val + a[u].c);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#endif
	cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T;
	while(T --){
		cin >> n;
		for(int i=1; i<=n; ++i){
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].id = i;
			a[i].val[1] = a[i].a, a[i].val[2] = a[i].b, a[i].val[3] = a[i].c;
		}
		if(n <= 10){
			dfs(1, 0, 0, 0, 0);
			cout << ans << '\n';
			ans = 0;
			continue;
		}
		else if(n <= 300){
			memset(dp, 0, sizeof dp);
			dp[0][0][0] = 0;
			for(int i=1; i<=n; ++i){
				for(int A=0; A<=n/2; ++A){
					for(int B=0; B<=n/2; ++B){
						dp[i][A][B] = max({dp[i-1][A][B], 
						(A ? (dp[i-1][A-1][B] + a[i].a) : -1), 
						(B ? (dp[i-1][A][B-1] + a[i].b) : -1), 
						dp[i-1][A][B] + a[i].c});
					}
				}
			}
			for(int A=0; A<=n/2; ++A){
				for(int B=0; B<=n/2; ++B){
				//if(dp[n][A][B] > 2e6)	cout << dp[n][A][B] << ' ';
					if(A + B < n/2) continue;
					ans = max(ans, dp[n][A][B]);
				}
			}
			cout << ans << '\n';
			ans = 0;
			continue;
		} 
		for(int i=1; i<=n; ++i) {
			vis[i] = 0;
			for(int j=1; j<=3; ++j){
				e[i + (j-1) * n].emplace_back(i+1, a[i].val[j]);
				e[i + (j-1) * n].emplace_back(i+1 + n, a[i].val[j]);
				e[i + (j-1) * n].emplace_back(i+1 + n+n, a[i].val[j]);
			} 
		}
		queue<int> q;
		q.push(1), q.push(n+1), q.push(n+n+1);
		while(q.size()){
			int cur = q.front();
			q.pop();
			for(auto [i, w] : e[cur]){
				f[i] = f[cur] + w;
				if((++ vis[i]) == 3) q.push(i);
			}
		}
		cout << max({f[n+1], f[n+n+1], f[n+n+n+1]}) << '\n';
		for(int i=1; i<=300300; ++i) e[i].clear();
		for(int i=1; i<=n+n+n+2; ++i) f[i] = 0, vis[i] = 0;
		ans = 0;
	}
	return 0;
}
/* 没事，我马上就要被 pop 掉了。 
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
