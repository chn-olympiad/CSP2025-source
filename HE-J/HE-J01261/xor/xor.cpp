#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node {
	LL x, y, sum;
};

const LL MAXN = 1e3 + 5; // 1-12 bc no more mem for array
LL a[MAXN], numxor[MAXN][MAXN];
bool vis[MAXN];
vector <node> v;

bool cmp(node x, node y) {
	if (x.x == y.x && x.sum == y.sum) return x.y < y.y;
	else if (x.x == y.x) return x.sum < y.sum;
	else return x.x > y.x;
} 

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n, k;
	cin >> n >> k;
	for (LL i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	for (LL i = 1; i <= n; i++) {
		for (LL j = i; j <= n; j++) {
			LL nw = a[i];
			for (LL k = i + 1; k <= j; k++) {
				nw ^= a[k];
			}
			numxor[i][j] = nw;
		}
	}
	for (LL i = 1; i <= n; i++) {
		for (LL j = i; j <= n; j++) {
			if (numxor[i][j] == k) {
				v.push_back({i, j, (j - i + 1)});
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	LL ans = 0;
	
	for (LL i = 0; i < v.size(); i++) {
		node t = v[i];
		bool flag = false;
		for (LL j = t.x; j <= t.y; j++) {
			if (vis[j]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;
		for (LL j = t.x; j <= t.y; j++) vis[j] = true;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
