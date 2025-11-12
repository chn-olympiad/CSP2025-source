#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 6e6 + 10;

/*
首先替换不会影响长度。
若一个变换存在多种替换的方案，那必然满足这个变换是个恒等变换。
因此判掉 t1=t2 的情况。这里需要一个 AC 自动机做匹配。
对于 t1!=t2，考虑找出最长公共前后缀。那么中间一块就是要替换的目标。
对于一个变换 s1!=s2 也做类似处理。
那么一个替换合法，当前仅当前中后三部分都能对上。
用特殊字符隔开跑匹配即可。这部分也是 AC 自动机。
注意到我们甚至能把两个 AC 自动机合起来写，好耶！ 
时间复杂度 O(n+q+L*sigma)。
诶我空间是不是爆了。
哦给了两个 G。太良心了！
*/

// 'a'~'z'+'{','|','}'

int c[MAXN][29], tot, fa[MAXN], cnt[2][MAXN];

inline 
void insert(string s, bool type) {
	int u = 0;
	for (char x : s) {
		if (!c[u][x - 'a']) c[u][x - 'a'] = ++tot;
		u = c[u][x - 'a'];
	}
	cnt[type][u]++;
}

inline 
void build() {
	queue<int> q;
	for (int i = 0; i < 29; i++) if (c[0][i]) q.emplace(c[0][i]);
	for (int u; !q.empty(); ) {
		u = q.front(), q.pop();
		cnt[0][u] += cnt[0][fa[u]], cnt[1][u] += cnt[1][fa[u]];
		for (int i = 0; i < 29; i++) {
			if (!c[u][i]) c[u][i] = c[fa[u]][i];
			else fa[c[u][i]] = c[fa[u]][i], q.emplace(c[u][i]);
		}
	}
}

inline 
ll query(string s, bool type) {
	int u = 0; ll ans = 0;
	for (char x : s) u = c[u][x - 'a'], ans += cnt[type][u];
	return ans;
}

int n, m; string s1, s2, tmp;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		if (s1 == s2) { insert(s1, 0); continue; }
		tmp = ""; int len = s1.length(), l = 0, r = 0;
		for (int i = 0; i < len; i++) if (s1[i] != s2[i]) { l = i; break; }
		for (int i = len - 1; ~i; i--) if (s1[i] != s2[i]) { r = i; break; }
		for (int i = 0; i < l; i++) tmp += s1[i];
		tmp += '{';
		for (int i = l; i <= r; i++) tmp += s1[i];
		tmp += '|';
		for (int i = l; i <= r; i++) tmp += s2[i];
		tmp += '}';
		for (int i = r + 1; i < len; i++) tmp += s2[i];
		insert(tmp, 1);
	}
	build();
	for (int i = 1; i <= m; i++) {
		cin >> s1 >> s2;
		if (s1 == s2) { cout << query(s1, 0) << "\n"; continue; }
		tmp = ""; int len = s1.length(), l = 0, r = 0;
		for (int i = 0; i < len; i++) if (s1[i] != s2[i]) { l = i; break; }
		for (int i = len - 1; ~i; i--) if (s1[i] != s2[i]) { r = i; break; }
		for (int i = 0; i < l; i++) tmp += s1[i];
		tmp += '{';
		for (int i = l; i <= r; i++) tmp += s1[i];
		tmp += '|';
		for (int i = l; i <= r; i++) tmp += s2[i];
		tmp += '}';
		for (int i = r + 1; i < len; i++) tmp += s2[i];
		cout << query(tmp, 1) << "\n";
	}
}
