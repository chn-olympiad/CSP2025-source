#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;

int n, q;
string s[maxn][2];
string t[maxn][2];
int ans;

bool check(int x, int y, int dis) {
	for (int i=dis; i<dis+s[y][0].size(); i++) {
		if (t[x][0][i] != s[y][0][i-dis] || t[x][1][i] != s[y][1][i-dis]) return false;
	}
	for (int i=dis+s[y][0].size(); i<t[x][0].size(); i++) {
		if (t[x][0][i] != t[x][1][i]) return false;
	}
	return true;
}

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for (int i=1; i<=q; i++) {
		ans = 0;
		cin >> t[i][0] >> t[i][1];
		for (int j=1; j<=n; j++) {
			int len1 = s[j][0].size(), len2 = t[i][0].size();
			for (int k=0; k<=len2-len1; k++) {
				if (k>0 && t[i][0][k-1] != t[i][1][k-1]) break;
				if (check(i, j, k)) ans++;
			}
		}
		cout << ans << '\n';
	}
	
}
