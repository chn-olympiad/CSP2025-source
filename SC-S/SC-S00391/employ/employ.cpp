#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 501;
const int mod = 998244353;
int c[N];
int S[N];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int res = 0;
	for(int i=0;i<s.size();i++) {
		res += (s[i] - '0');
	}
	s = "a" + s;
	if(res == 0) {
		cout << 0;
		return 0;
	}
	if(m == n && res < n) {
		cout << 0;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		cin >> c[i];
		S[i] = i;
	}
	res = 0;
	do {
		int A = 0,R = 0;
		for(int i=1;i<=n;i++) {
			int tp = S[i];
			if(R >= c[S[i]]) {
				R++;
				continue;
			}
			if(s[i] == '0') {
				R++;
				continue;
			}else {
				A++;
				if(A >= m) {
					break;
				}
				continue;
			}
		}
		if(A >= m) {
			res = (res + 1) % 998244353;
		}
	}while(next_permutation(S + 1,S + n + 1));
	cout << res;
	return 0;
}
