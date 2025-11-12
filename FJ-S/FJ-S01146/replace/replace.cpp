#include<bits/stdc++.h>
#define INF 1e13
#define int long long
using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10, K = 11;

int T;

int n, q;
int ans;
string s[N][3];
string t[3];

int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return f * x;
}

void solve(){
	n = read(), q = read();
	for(int i = 1; i <= n; ++i) cin >> s[i][1] >> s[i][2];
	
	while(q--){
		ans = 0;
		
		cin >> t[1] >> t[2];
		for(int len = 1; len <= t[1].size(); ++len)
			for(int l = 0; l + len - 1 < t[1].size(); ++l){
				int r = l + len;
				for(int k = 1; k <= n; ++k){
					if(r == t[1].size() || t[1].substr(r, t[1].size() - r) == t[2].substr(r, t[1].size() - r))
						if(t[1].substr(0, l) == t[2].substr(0, l))
							if(t[1].substr(l, len) == s[k][1] && t[2].substr(l, len) == s[k][2])
								ans++;
				}
			}
		printf("%lld\n", ans);
	}
	return;
}

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	T = 1;
//	T = read();
	while(T--)
		solve();
	return 0;
}

/*

*/
