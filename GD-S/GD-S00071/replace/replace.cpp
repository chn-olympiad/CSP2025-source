#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const int M = 5e6 + 5;
typedef unsigned long long ull;
const ull base = 443;
const int S = 26;
#define all(x) x.begin(), x.end()

//bool MemoryST = false;

int n, q;
char s[M], t[M];
int ch[M][S] = {{0}};
int num;
int insrt(int l, int r, int d) {
	int cur = 0;
	for (int i = l; i != r + d; i += d) {
		if (!ch[cur][s[i] - 'a']) ch[cur][s[i] - 'a'] = ++num;
		cur = ch[cur][s[i] - 'a']; 
	}
	return cur;
}
int sz[M] = {0}, dfn[M] = {0}, cur = 0;
int dfs(int x) {
	sz[x] = 1, dfn[x] = ++cur;	
	for (int i = 0; i < S; i++) 
		if (ch[x][i])
			sz[x] += dfs(ch[x][i]);
	return sz[x]; 
}

map<ull, int> idx;
int tot = 0;
struct Node {
	int x, y, op, id;
	Node (int _x = 0, int _y = 0, int _op = 0, int _id = 0) :
		x(_x), y(_y), op(_op), id(_id) {}
};
int getid(ull x) {
	if (idx.count(x)) return idx[x];
	return idx[x] = ++tot; 
}
vector<Node> res[N];

void add(int op, int id = 0) {
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	int lenS = (int)strlen(s + 1);
	int lenT = (int)strlen(t + 1);
	if (lenS != lenT) return;
	int len = lenS;
	int l = 0, r = len + 1;
	for (int i = 1; i <= len; i++) if (s[i] != t[i]) r = i;
	for (int i = len; i >= 1; i--) if (s[i] != t[i]) l = i;
	if (l == 0) return;
	ull sum = 0;
	for (int i = l; i <= r; i++) {
		sum = sum * base + s[i];
		sum = sum * base + t[i];
	}
	int u = getid(sum);
	
	int x = insrt(l - 1, 1, -1);
	int y = insrt(r + 1, len, 1);
	res[u].push_back(Node(x, y, op, id));
}

int b[N << 1] = {0}, m = 0;//b最多是 2 * 2 + 2 = 6, 这里开到 8
int T[N << 1] = {0};
int lowbit(int x) {
	return x & -x; 
}
void mdf(int x, int v) {
	while (x <= m) T[x] += v, x += lowbit(x);
}
int qry(int x) {
	int ans = 0;
	while (x) ans += T[x], x -= lowbit(x);
	return ans;
}

int ans[N] = {0};
struct node {
	int x, y, v, id;
	node (int _x = 0, int _y = 0, int _v = 0, int _id = 0) :
		x(_x), y(_y), v(_v), id(_id) {}
} tmp[N << 2];
bool cmp(node u, node v) {
	if (u.x != v.x) return u.x < v.x;
	if (u.y != v.y) return u.y < v.y;
	return u.id < v.id;
}

void slv(vector<Node> &v) {
	int len = 0;
	m = 0;
	for (auto i: v) {
		int x = i.x, y = i.y;
		if (i.op == 0) {
			tmp[++len] = node(dfn[x], dfn[y], 1, 0);
			tmp[++len] = node(dfn[x] + sz[x], dfn[y], -1, 0);
			tmp[++len] = node(dfn[x], dfn[y] + sz[y], -1, 0);
			tmp[++len] = node(dfn[x] + sz[x], dfn[y] + sz[y], 1, 0);
			b[++m] = dfn[y], b[++m] = dfn[y] + sz[y];
		}
		else {
			tmp[++len] = node(dfn[x], dfn[y], 0, i.id);
			b[++m] = dfn[y];
		}
	}
	
	sort(b + 1, b + m + 1);
	m = unique(b + 1, b + m + 1) - b - 1;
	for (int i = 1; i <= m; i++) T[i] = 0;
	
	sort(tmp + 1, tmp + len + 1, cmp);
	for (int i = 1; i <= len; i++) {
		tmp[i].y = lower_bound(b + 1, b + m + 1, tmp[i].y) - b;
		if (tmp[i].id == 0) 
			mdf(tmp[i].y, tmp[i].v);
		else {
			ans[tmp[i].id] = qry(tmp[i].y);
		}
	}
}

//bool MemoryEd = false;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) add(0);
	for (int i = 1; i <= q; i++) add(1, i);
	dfs(0);
//	cout << m << " " << tot << endl;return 0;//
	for (int i = 1; i <= tot; i++) slv(res[i]);
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
//	cerr << (&MemoryST - &MemoryEd) / 1024. / 1024. << endl;
	return 0;
}
