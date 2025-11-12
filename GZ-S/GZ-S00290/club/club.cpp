//GZ-S00290 贵阳市白云区华师一学校 
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define PII pair<int, int>
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, l, r) for (int i = l; i >= r; i--)
using namespace std;

const int N = 1e5 + 5;

struct Node{
	int x, id, typ;
	bool operator < (const Node W) const {
		return x > W.x;
	}
}a[N * 3];

int n;
bool st[N];
int aa[N][3];

void solve() {
	memset(st, 0, sizeof st);
	int res = 0;
	cin >> n;
	int tot = 0;
	upp(i, 1, n) {
		cin >> aa[i][1] >> aa[i][2] >> aa[i][3];
		a[++tot] = {aa[i][1], i, 1};
		a[++tot] = {aa[i][2], i, 2};
		a[++tot] = {aa[i][3], i, 3};
	}
	sort(a + 1, a + tot + 1);
	priority_queue<PII, vector<PII>, greater<PII>>p[4];
	upp(i, 1, tot) {
		if (st[a[i].id]) continue;
		st[a[i].id] = 1;
		p[a[i].typ].push({a[i].x, a[i].id});
		res += a[i].x;
	}
	priority_queue<int, vector<int>, greater<int> > h;
	upp(i, 1, 3) {
		if (p[i].size() <= n / 2) continue;
		int sum = p[i].size() - n / 2;
		while(p[i].size()) {
			int t1, t2;
			int id = p[i].top().second;
			p[i].pop();
			if (i == 1) t1 = 2, t2 = 3;
			if (i == 2) t1 = 1, t2 = 3;
			if (i == 3) t1 = 1, t2 = 2;
			h.push(min(aa[id][i] - aa[id][t1], aa[id][i] - aa[id][t2]));
		}
		while(sum) res -= h.top(), h.pop(), sum--;
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while(T--) solve();
	
	return 0;
}
