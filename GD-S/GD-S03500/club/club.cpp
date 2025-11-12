#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int ll

const int N = 100000 + 10;
const int inf = 1000000007;
using namespace std;

int read () {
	int x = 0, k = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') k = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * k;
}

using Pii = pair<int, int>;
using Ary = array<Pii, 3>;
int T, ret, n; priority_queue<int, vector<int>, greater<int>> Q[4];
struct E { Ary val; int col, id; } s[N];

void work () {
	while (!Q[1].empty()) Q[1].pop();
	while (!Q[2].empty()) Q[2].pop();
	while (!Q[3].empty()) Q[3].pop();
	n = read(), ret = 0;
	for (int i = 1, a, b, c; i <= n; ++i) {
		a = read(), b = read(), c = read();
		s[i].val[0] = Pii(a, 1), s[i].val[1] = Pii( b, 2), s[i].val[2] = Pii(c, 3);
		sort(s[i].val.begin(), s[i].val.end());
		s[i].id = i, s[i].col = s[i].val[2].second;
		Q[s[i].col].push(s[i].val[2].first - s[i].val[1].first);
		ret += s[i].val[2].first;
	}
	int ExQ = -1; for (int i = 1; i <= 3; ++i) if (2 * (int)Q[i].size() > n) ExQ = i;
	if (ExQ == -1) return cout << ret << endl, void();
	while (2 * (int)Q[ExQ].size() > n) ret -= Q[ExQ].top(), Q[ExQ].pop();
	cout << ret << endl;
}

signed main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--) work();
	return 0;	
}

/*
weiyuyun 15:12
*/
