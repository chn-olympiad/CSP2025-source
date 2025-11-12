#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 5000005;
int n, q;
struct Node {
	int nxt[26], fail, fa, fr, to, len;
	bool end; int lst;
} tr1[N], tr2[N]; int tot1, tot2;
string s1, s2;
int end1[N], end2[N], cnt;

void Push(int x) {
	int j = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (!tr1[j].nxt[s1[i] - 'a']) {
			++tot1; tr1[j].nxt[s1[i] - 'a'] = tot1;
			tr1[tot1].fa = j, tr1[tot1].fr = s1[i] - 'a';
			tr1[tot1].len = tr1[j].len + 1;
		} j = tr1[j].nxt[s1[i] - 'a'];
	} end1[x] = j; tr1[j].end = 1; tr1[j].to = x; j = 0;
	for (int i = 0; i < s2.length(); i++) {
		if (!tr2[j].nxt[s2[i] - 'a']) {
			++tot2; tr2[j].nxt[s2[i] - 'a'] = tot2;
			tr2[tot2].fa = j, tr2[tot2].fr = s2[i] - 'a';
			tr2[tot2].len = tr2[j].len + 1;
		} j = tr2[j].nxt[s2[i] - 'a'];
	} end2[x] = j; tr2[j].end = 1; tr2[j].to = x;
}

queue<int> Q;
void Init() {
	Q.push(0);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		if (u && tr1[u].fa) {
			for (tr1[u].fail = tr1[tr1[u].fa].fail; tr1[u].fail; tr1[u].fail = tr1[tr1[u].fail].fail)
				if (tr1[tr1[u].fail].nxt[tr1[u].fr]) break;
			tr1[u].fail = tr1[tr1[u].fail].nxt[tr1[u].fr];
		}
		tr1[u].lst = tr1[tr1[u].fail].lst; if (tr1[tr1[u].fail].end) tr1[u].lst = tr1[u].fail;
		for (int i = 0; i < 26; i++) if (tr1[u].nxt[i]) Q.push(tr1[u].nxt[i]);
	}
	Q.push(0);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		if (u && tr2[u].fa) {
			for (tr2[u].fail = tr2[tr2[u].fa].fail; tr2[u].fail; tr2[u].fail = tr2[tr2[u].fail].fail)
				if (tr2[tr2[u].fail].nxt[tr2[u].fr]) break;
			tr2[u].fail = tr2[tr2[u].fail].nxt[tr2[u].fr];
		}
		tr2[u].lst = tr2[tr2[u].fail].lst; if (tr2[tr2[u].fail].end) tr2[u].lst = tr2[u].fail;
		for (int i = 0; i < 26; i++) if (tr2[u].nxt[i]) Q.push(tr2[u].nxt[i]);
	}
}

void run() {
	cin >> s1 >> s2; cnt = 0;
	int pre = 0, suf = s1.length() - 1;
	for (; s1[pre] == s2[pre]; pre++); pre--;
	for (; s1[suf] == s2[suf]; suf--); suf++;
	int p1 = 0, p2 = 0;
	for (int i = 0; i < s1.length(); i++) {
		for (; p1; p1 = tr1[p1].fail) if (tr1[p1].nxt[s1[i] - 'a']) break;
		p1 = tr1[p1].nxt[s1[i] - 'a'];
		for (; p2; p2 = tr2[p2].fail) if (tr2[p2].nxt[s2[i] - 'a']) break;
		p2 = tr2[p2].nxt[s2[i] - 'a'];
		int P1 = p1, P2 = p2;
		while (P1) {
			while (tr2[P2].len > tr1[P1].len) P2 = tr2[P2].lst;
			if (tr1[P1].to && tr2[P2].to && tr1[P1].to == tr2[P2].to) break;
			P1 = tr1[P1].lst;
		}// cout << P1 << ' ' << P2 << endl;
		if (i + 1 >= suf && i - tr1[P1].len <= pre) cnt++;
	} cout << cnt << '\n';
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2; Push(i);
	} Init();
//	for (int i = 0; i <= tot1; i++) {
//		cout << tr1[i].to << ' ';
//	} cout << endl;
//	for (int i = 0; i <= tot2; i++) {
//		cout << tr2[i].to << ' ';
//	} cout << endl;
	while (q--) run();
}
