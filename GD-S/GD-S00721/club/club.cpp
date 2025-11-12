#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair
#define fi first
#define se second
#define db double
#define pii pair < int, int >

const int MAXN = 1e5 + 7;

vector < ll > f[4]; 

ll n, A[MAXN][4], B[MAXN];

void Solve() {
	cin >> n;
	f[1].clear(); f[2].clear(); f[3].clear();
	ll ans = 0, cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> A[i][1] >> A[i][2] >> A[i][3];
		if (A[i][1] >= A[i][2] && A[i][1] >= A[i][3]) f[1].push_back(i), ans += A[i][1];
		else if (A[i][2] >= A[i][1] && A[i][2] >= A[i][3]) f[2].push_back(i), ans += A[i][2];
		else f[3].push_back(i), ans += A[i][3];
	}
	ll a = f[1].size(), b = f[2].size(), c = f[3].size();
	if (a > n / 2) {
		for (auto i : f[1]) B[++ cnt] = A[i][1] - max(A[i][2], A[i][3]);
		sort(B + 1, B + 1 + cnt);
		for (int i = 1; i <= a - n / 2; i ++) ans -= B[i];
	} else if (b > n / 2) {
		for (auto i : f[2]) B[++ cnt] = A[i][2] - max(A[i][1], A[i][3]);
		sort(B + 1, B + 1 + cnt);
		for (int i = 1; i <= b - n / 2; i ++) ans -= B[i];
	} else {
		for (auto i : f[3]) B[++ cnt] = A[i][3] - max(A[i][2], A[i][1]);
		sort(B + 1, B + 1 + cnt);
		for (int i = 1; i <= c - n / 2; i ++) ans -= B[i];
	}
	cout << ans << '\n';
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	while (T --) Solve();
	return 0;
}
/*
别紧张！
T1：贪心搞个堆做完了
考虑贪心正确性,看上去是对的，看上去不对了 
傻逼了 
14:50通过T1用时20min太傻逼了 
*/
