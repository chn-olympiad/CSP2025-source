#include<bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define LL long long
#define fer(i, a, b, args...) for(int i = (a), ##args; i <= (b); i ++)
#define fel(i, a, b, args...) for(int i = (a), ##args; i >= (b); i --)
template <typename T> void chmin(T &x, T y) { if(y < x) x = y; }
template <typename T> void chmax(T &x, T y) { if(y > x) x = y; }
#define fi first
#define se second 
constexpr int N = 2e5 + 10; 
int T; 
int n; 
struct node {
	int v, id; 
	bool operator < (const node &a) const {
		return v > a.v; 
	}
}; 
node a[N][3]; 
void solve() {
	cin >> n;
	priority_queue <int> q[3]; 
	LL ans = 0; 
	fer(i, 1, n) {
		fer(j, 0, 2) {
			cin >> a[i][j].v; 
			a[i][j].id = j; 
		}
		sort(a[i], a[i] + 3);
		int k = a[i][0].id; 
		q[k].push(a[i][1].v - a[i][0].v); 
		ans += a[i][0].v; 
		if(q[k].size() > n / 2) {
			ans += q[k].top(); 
			q[k].pop(); 
		}
	}
	cout << ans << endl; 
}
signed main() {
	// freopen("club5.in", "r", stdin); 
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 
	cin >> T; 
	while(T --) {
		solve(); 
	}
	return 0; 
}