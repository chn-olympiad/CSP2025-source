#include <bits/stdc++.h>
#define space putchar(' ')
#define newline puts("")
#define int long long
using namespace std;

const int N = 200005;
int n, q, cnt, ans;
string s[N][5], t1, t2;

bool check(int l, int r){
	for(int i = 0; i < l; ++i){
		if(t1[i] != t2[i]) return false;
	}
	for(int i = r + 1; i < t1.size(); ++i){
		if(t1[i] != t2[i]) return false;
	}
	return true;
}

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> s[i][1] >> s[i][2];
	}
	while(q--){
		cin >> t1 >> t2;
		int len1 = t1.size(), len2 = t2.size();
		if(len1 != len2){
			cout << 0 << '\n';
			continue;
		}
		ans = 0;
		for(int i = 1; i <= n; ++i){
			cnt = 0;
			for(int j = 0; j < len1; ++j){
				if(j + s[i][1].size() - 1 < len1 && j + s[i][2].size() - 1 < len2 && (t1.substr(j, j + s[i][1].size() - 1) == s[i][1].c_str()) && (t2.substr(j, j + s[i][2].size() - 1) == s[i][2].c_str()) && check(j, j + s[i][1].size() - 1)) ++cnt;
			}
			ans += cnt;
		}
		cout << ans << "\n";
	}
	return 0;
}
