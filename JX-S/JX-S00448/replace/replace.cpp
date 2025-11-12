#include <bits/stdc++.h>
#define int unsigned long long
#define PII pair <int, int>
#define N 5000005
const int INF = 1e18;
using namespace std;

int n, q, l[N];
string s[N][2];

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1],
		l[i] = s[i][0].size();
	while(q--){
		string t[2]; cin >> t[0] >> t[1];
		if(t[0].size() != t[1].size()){
			cout << 0 << '\n';
			continue;
		}
		int cnt = 0;
		for(int i = 0; i < t[0].size(); i++){
			for(int j = 1; j <= n; j++)
				if(t[0].substr(i, l[j]) == s[j][0]){
					if(t[0].substr(0, i) + s[j][1] + t[0].substr(i + l[j]) == t[1])
						cnt++;
				}
		}
		cout << cnt << '\n';
	}
}

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--)
		solve();
	return 0;
}
