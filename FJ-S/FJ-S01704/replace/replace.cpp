# include<bits/stdc++.h>
# define N 200005
# define L 5000005
using namespace std;
int n, q, ans, head, tail, c[N];
string a[N], b[N];
vector<int> h, t;
int f[L], g[L], vis[L];
void KMP(string x, string y, int op) {
	int j = 0;
	for(int i = 2; i < x.size(); i ++) {
		while(j != 0 && x[i] != x[j]) j = f[j];
		if(x[i] == x[j])
			f[i] = ++ j;
	}
	j = 0;
	for(int i = 0; i < y.size(); i ++) {
		while(j != 0 && (y[i] != x[j] || j == x.size())) j = f[j];
		if(y[i] == x[j])
			g[i] = ++ j;
		if(j == x.size())
			if(op == 1)
				h.push_back(i - j + 1);
			else
				t.push_back(i - j + 1);
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
		cin >> a[i] >> b[i], c[i] = a[i].size();
	while(q --) {
		ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		head = 0, tail = t1.size() - 1;
		while(t1[head] == t2[head] && head <= t1.size() - 1)
			head ++;
		while(t1[tail] == t2[tail] && tail >= 0)
			tail --;
		for(int i = 1; i <= n; i ++) {
			h.clear(), t.clear();
			KMP(a[i], t1, 1);
			KMP(b[i], t2, 2);
			for(int j = 0; j < t.size(); j ++)
				vis[t[j]] = 1;
			for(int j = 0; j < h.size(); j ++) {
				int l = h[j], r = h[j] + c[i] - 1;
				if(! vis[l]) continue;
				if(l <= head && tail <= r)
					ans ++;
			}
			for(int j = 0; j < t.size(); j ++)
				vis[t[j]] = 0;
		}
		cout << ans << "\n";
	}
	return 0;
}