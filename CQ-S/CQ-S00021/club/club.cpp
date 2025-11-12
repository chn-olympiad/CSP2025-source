#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int t, n; 
ll a[5][N];
ll q[5][N];
ll _[5];
ll ans = 0;
void dfs(int x){
	if(x > n){
		ll sum = 0;
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= _[i]; j++){
				sum += q[i][j];
			}
		}
		ans = max(ans, sum);
		return ;
	}
	for(int i = 1; i <= 3; i++){
		if(_[i] + 1 <= n / 2){
			q[i][++_[i]] = a[i][x];
			dfs(x + 1);
			_[i]--;
		}
	}
}

ll dp[40][20][20][20];

struct bi{
	ll a, b;
	ll c;
}b[N];
bool cmp(bi i, bi j){
	if(i.a == j.a) return i.b > j.b;
	return i.a > j.a;
}
priority_queue<ll, vector<ll>, greater<ll> > bb;

ll dp1[110][110][110];
ll dp2[110][110][110];

void init(){
	ans = 0;
	memset(_, 0, sizeof _);
	memset(q, 0, sizeof q);
	memset(dp, 0, sizeof dp);
	memset(dp1, 0, sizeof dp1);
	for(int i = 0; i < N; i++){
		b[i] = {0, 0, 0};
	}
	while(!bb.empty()) bb.pop();
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		init();
		cin >> n;
		bool A = true, B = true; 
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[j][i];
				if(j != 1 && a[j][i] != 0) A = false; 
				if(j == 3 && a[j][i] != 0) B = false;
			}
		}
		if(A){
			sort(a[1] + 1, a[1] + n + 1);
			for(int i = n; i > n / 2; i--){
				ans += a[1][i];
			}
			cout << ans << '\n';
		}
		else if(B){
			for(int i = 1; i <= n; i++){
				b[i] = {a[1][i], a[2][i], a[1][i] - a[2][i]};
			}
			sort(b + 1, b + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++){
				ans += b[i].a;
				bb.push(b[i].c);
			}
			for(int i = n / 2 + 1; i <= n; i++){
				ans += b[i].b;
			}
			for(int i = n / 2 + 1; i <= n; i++){
				if(b[i].c > bb.top()){
					ans -= bb.top();
					ans += b[i].c;
					bb.pop();
					bb.push(b[i].c);
				}
			}
			cout << ans << '\n';
		}
		else if(n <= 10){
			dfs(1);
			cout << ans << '\n';
		}
		else if(n <= 30){
			for(int i = 1; i <= n; i++){
				for(int bm = 0; bm <= n / 2; bm++){
					for(int bm_ = 0; bm_ <= n / 2; bm_++){
						for(int bm__ = 0; bm__ <= n / 2; bm__++){
							if(bm + bm_ + bm__ != i) continue;
							if(bm > 0) dp[i][bm][bm_][bm__] = max(dp[i - 1][bm - 1][bm_][bm__] + a[1][i], dp[i][bm][bm_][bm__]);
							if(bm_ > 0) dp[i][bm][bm_][bm__] = max(dp[i - 1][bm][bm_ - 1][bm__] + a[2][i], dp[i][bm][bm_][bm__]);
							if(bm__ > 0) dp[i][bm][bm_][bm__] = max(dp[i - 1][bm][bm_][bm__ - 1] + a[3][i], dp[i][bm][bm_][bm__]);
						}
					}
				}
			}
			for(int bm = 0; bm <= n / 2; bm++){
				for(int bm_ = 0; bm_ <= n / 2; bm_++){
					for(int bm__ = 0; bm__ <= n / 2; bm__++){
						if(bm + bm_ + bm__ != n) continue;
						ans = max(ans, dp[n][bm][bm_][bm__]);
					}
				}
			}
			cout << ans << '\n';
		} 
		else if(n <= 200){
			for(int i = 1; i <= n; i++){
				for(int bm = n / 2; bm >= 0; bm--){
					for(int bm_ = n / 2; bm_ >= 0; bm_--){
						int bm__ = i - bm - bm_;
						if(bm__ < 0) continue;
						dp2[bm][bm_][bm__] = dp1[bm][bm_][bm__];
						if(bm > 0) dp1[bm][bm_][bm__] = max(dp1[bm - 1][bm_][bm__] + a[1][i], dp1[bm][bm_][bm__]);
						if(bm_ > 0) dp1[bm][bm_][bm__] = max(dp1[bm][bm_ - 1][bm__] + a[2][i], dp1[bm][bm_][bm__]);
						if(bm__ > 0) dp1[bm][bm_][bm__] = max(dp2[bm][bm_][bm__ - 1] + a[3][i], dp1[bm][bm_][bm__]);
					}
				}
			}
			for(int bm = 0; bm <= n / 2; bm++){
				for(int bm_ = 0; bm_ <= n / 2; bm_++){
					int bm__ = n - bm - bm_;
					if(bm__ < 0) continue;
					ans = max(ans, dp1[bm][bm_][bm__]);
				}
			}
			cout << ans << '\n';
		}
		else{
			dfs(1);
			cout << ans << '\n';
		}
	}
	return 0;
}
//14 : 41 20pts
//14 : 57 25pts
//15 : 29 45pts
//16 : 24 60pts
