// A:task: n = 2/4
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 10;

struct Node {
	int a, b, c;
} p[N];

int t;
int n;

void task1() {
	int a, b, c;
	int _a, _b, _c;
	cin >> a >> b >> c;
	cin >> _a >> _b >> _c;
	int sum = 0;
	if (a + _b >= sum) sum = a + _b;
	if (a + _c >= sum) sum = a + _c;
	if (_a + b >= sum) sum = _a + b;
	if (_a + c >= sum) sum = _a + c;
	cout << sum << "\n";
}

bool check(int ai, int aj, int bi, int bj, int ci, int cj) {
	int s[7];
	s[1] = ai, s[2] = bj, s[3] = aj, s[4] = bi, s[5] = ci, s[6] = cj;
	for (int i = 1; i <= 6; i ++ ) {
		for (int j = 1; j != i && j <= 6; j ++ ) {
			if (s[i] == s[j] && s[i] * s[j] != 0) return false;
		}
	}
	
	return true;
}

void task2() {
	p[0].a = 0, p[0].b = 0, p[0].c = 0;
	for (int i = 1; i <= n; i ++ ) cin >> p[i].a >> p[i].b >> p[i].c;
	int sum = -1;
	for (int ai = 0; ai <= 4; ai ++ ) {
		for (int aj = 0; aj <= 4; aj ++ ) {
			for (int bi = 0; bi <= 4; bi ++ ) {
				for (int bj = 0; bj <= 4; bj ++ ) {
					for (int ci = 0; ci <= 4; ci ++ ) {
						for (int cj = 0; cj <= 4; cj ++ ) {
							if (!check(ai, aj, bi, bj, ci, cj)) continue;
							sum = max(sum, p[ai].a + p[aj].a + p[bi].b + p[bj].b + p[ci].c + p[cj].c);
//							cout << ai << " " << aj << " " << bi << " " << bj << " " << ci << " " << cj << " " << sum << " \n";
						}
					}
				}
			}
		}
	}
	
	cout << sum << "\n";
}

void task1200() {
	vector<int> ans;
	for (int i = 1; i <= n; i ++ ) ans.push_back(p[i].a);
	sort(ans.begin(), ans.end());
	int sum = 0;
	for (int i = 1e5 / 2; i <= 1e5; i ++ ) {
		sum += ans[i];
	}
	
	cout << sum << "\n";
}


void taskall() {
	cin >> n;
	bool flag12 = true, flag134 = true;
	for (int i = 1; i <= n; i ++ ) {
		cin >> p[i].a >> p[i].b >> p[i].c;
		if (p[i].b != 0) flag12 = false;
		if (p[i].c != 0) flag134 = false;
	}
	
	if (flag12) task1200();
}

void solve() {
	cin >> n;
	if (n == 2) task1();
	else if (n == 4) task2();
	else taskall();
}

int main(int argc, char *argv[]) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	
	while (t -- ) {
		solve();
	}
	
	return 0;
}
