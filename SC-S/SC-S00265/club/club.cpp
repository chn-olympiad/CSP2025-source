#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el cout << '\n'
#define AC return
#define pii pair <int, int> 
void main_();
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = 1;
	cin >> t;
	while(t--) main_();
	return 0;
}
const int maxn = 1e5 + 18;

int n, a[maxn][5], ans, cnt = 0;
vector <pii> vec;
struct node {
	int a, b, i, a1, b1;
}pos[maxn];
bool cmp1(node a, node b) {
	if(a.a != b.a) return a.a > b.a;
	else return a.b > b.b;
}
bool cmp2(pii a, pii b) {
	return a.first > b.first;
}

namespace s1 {
	const int N = 206;
	int dp[N][N], sum;
	void solve() {
//		for(int i = 1; i <= n; i++) {
//			sum += a[i][3];
//			a[i][1] -= a[i][3];
//			a[i][2] -= a[i][3];
//		}
		int ans = 0;
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= n; j++) {
				dp[i][j] = -1e16;
			}
		}
		dp[0][0] = 0;
		for(int x = 1; x <= n; x++) {
			for(int i = n / 2; i >= 0; i--) {
				for(int j = n / 2; j >= 0; j--) {
					dp[i][j] = dp[i][j] + a[x][3]; 
					if(i == 0 && j == 0) continue;
					else if(i == 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[x][2]);
					else if(j == 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[x][1]);
					else dp[i][j] = max(max(dp[i - 1][j] + a[x][1], dp[i][j - 1] + a[x][2]), dp[i][j]);
//					dp[i][j] = max(dp[i][j], lst);
					if((n - i - j) <= n / 2) ans = max(ans, dp[i][j]);
				}
			}
		}
		cout << ans; el;
	}
}

void main_() {
	ans = 0;
	cnt = 0;
	cin >> n;
	vec.clear();
	cnt = n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		ans += a[i][1];
		pos[i].a = -a[i][1] + a[i][2];
		pos[i].a1 = 2;
		pos[i].b = -a[i][1] + a[i][3];
		pos[i].b1 = 3;
		pos[i].i = i;
		if(pos[i].b > pos[i].a) swap(pos[i].b, pos[i].a), swap(pos[i].a1, pos[i].b1);
//		cout << ans; el;
	}
	if(n <= 200) {
		s1 :: solve();
		AC;
	}
	sort(pos + 1, pos + n + 1, cmp1);
	for(int i = 1; i <= n; i++) {
		if(cnt > n / 2 || pos[i].a > 0) {
			cnt--;
			ans -= a[pos[i].i][1];
			ans += a[pos[i].i][2];
			vec.push_back({-a[pos[i].i][2] + a[pos[i].i][3], pos[i].i});
//			cout << pos[i].i << ' ';
		}
		else break;
	}
//	el;
	sort(vec.begin(), vec.end(), cmp2);
	
	cnt = vec.size();
	int cur = 0;
	for(pii tmp : vec) {
		int i = tmp.second, num = tmp.first;
		if(cnt > n / 2 || (num > 0 && cur < n / 2)) {
			cnt--;
			cur++;
//			cout << i << ' ';
			ans += num;
		} 
		else break;
	}
//	el;
//	cout << '*';
	cout << ans; el;
}



/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
*/







