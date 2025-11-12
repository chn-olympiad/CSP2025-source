#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, q; string s[maxn][3];
int fail[maxn];

inline int cnt(string t, int id, string d) {
	int n = (int)t.length(), m = (int)s[id][1].length(), res = 0;
	for(int i = 2, j = 0; i < m; i++) {
		while(j && s[id][1][i] != s[id][1][j + 1]) j = fail[j];
		if(s[id][1][i] == s[id][1][j + 1]) j++;
		fail[i] = j;
	}
	for(int i = 0, j = 0; i < n; i++) {
		while(j && t[i] != s[id][1][j + 1]) j = fail[j];
		if(t[i] == s[id][1][j + 1]) j++;
		if(j == m - 1) {
			string tmp = t;
			for(int k = i - j + 1; k <= i; k++) tmp[k] = s[id][2][k - i + j];
			if(tmp == d) res++;
		}
	} return res;
}

int main() {
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2], s[i][1] = "0" + s[i][1];
	for(int i = 1; i <= q; i++) {
		string t1, t2; int res = 0;
		for(int j = 1; j <= n; j++) res += cnt(t1, j, t2);
		cout << res << "\n";
	}
	
	return 0;
}