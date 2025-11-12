#include <iostream>
using namespace std;
const int N = 5000100;

string s1[N], s2[N];
int cn;
int nxt[N][26];
int f[N], ots[N];
int endi[N];

void insert(string s, int si)
{
	int now = 0;
	for (int i = 0; i < s.size(); i++) {
		int j = s[i] - 'a';
		if (!nxt[now][j]) {
			nxt[now][j] = ++cn;
			f[cn] = now;
			now = cn;
		} else now = nxt[now][j];
	}
	now = 0;
	for (int i = 0; i < s.size(); i++) {
		now = nxt[now][s[i] - 'a'];
	}
	endi[cn] = si;
}

void build(int x, int c)
{
	int p = f[x];
    if (ots[p] && nxt[ots[p]][c] && nxt[ots[p]][c] != x) {
    	ots[x] = nxt[ots[p]][c];
	}
	for (int i = 0; i < 26; i++) {
		if (!nxt[x][i]) nxt[x][i] = nxt[ots[p]][i];
	}
	for (int i = 0; i < 26; i++) {
		if (f[nxt[x][i]] == x && nxt[x][i]) {
			build(nxt[x][i], i);
		}
	}
}

int main()
{
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		insert(s2[i], i);
	}
	int x = 1, y = 1;
	build(0, -1);
	for (int i = 1; i <= q; i++) {
		string a, b;
		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << 0 << '\n';
			continue;
		}
		int sz = a.size();
		int sami = -1;
		int now = 0, ans = 0;
		for (int i = 0; i < sz; i++) {
			if (a[i] == b[i] && sami == i - 1) sami++;
			char ch = b[i] - 'a';
			now = nxt[now][ch];
			int nnow = now;
			while (nnow != 0) {
				int sze = s2[endi[now]].size();
				if (sami < i - sze) break;
				bool fff = 1;
				for (int j = 0; j < sze; j++) {
					if (a[i - sze + 1 + j] != s1[endi[now]][j]) {
						fff = 0;
						break;
					}
				}
				if (fff) ans++;
				nnow = ots[nnow];
			}
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex







*/




