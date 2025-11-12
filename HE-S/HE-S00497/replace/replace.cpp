#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N = 4e5 + 10 , M = 5e6 + 10;
const int bas = 31 , p = 1e9 + 21;
int n , q , ans;
string s[N][2];
vector<ull> ht[2];
string t[2];
ull B[M] , hs[N][2];
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
aaaa bbbb
xabcx xadex

*/
//vector<array<int , 3> > v[N];

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	B[0] = 1;
	for(int i = 1;i < M;i ++) B[i] = B[i - 1] * bas;
	bool fg = 1;
	for(int i = 1;i <= n;i ++) {
		cin >> s[i][0] >> s[i][1];
		int len = s[i][0].size();
		for(int j = 0;j < 2;j ++) {
			ull nb = (s[i][j][0] - 'a');
			for(int k = 1;k < len;k ++) {
				if(s[i][j][k] - 'a' > 1) fg = 0;
				nb = nb + (s[i][j][k] - 'a') * B[k];
			}
			hs[i][j] = nb;
		}
	}
//	if(fg && n == 200000) {
//		for(int i)
//	}
//	cerr << "n , q = " << n << "," << q << endl;
	for(int i = 1;i <= q;i ++) {
		cin >> t[0] >> t[1]; ans = 0;
		if(t[0].size() != t[1].size()) {
			cout << 0 << "\n";
			continue;
		}
		int R = t[0].size();
		for(int j = 0;j < 2;j ++) {
			ht[j].clear();
			ht[j].push_back(t[j][0] - 'a');
			for(int k = 1;k < R;k ++) {
				ull nb = ht[j].back() + (t[j][k] - 'a') * B[k];
				ht[j].push_back(nb);
			}
		}
		R --;
		int L = 0;
		while(L < R && t[0][L] == t[1][L]) L ++;
		while(L < R && t[0][R] == t[1][R]) R --;
		for(int j = 1;j <= n;j ++) {
			int len = s[j][0].size();
			for(int k = max(R - len + 1 , 0);k <= L && k + len - 1 < t[0].size();k ++) {
				ull ck1 = k ? ht[0][k + len - 1] - ht[0][k - 1] : ht[0][k + len - 1];
				ull ck2 = hs[j][0] * B[k];
				if(ck1 != ck2) continue;
				ck1 = k ? ht[1][k + len - 1] - ht[1][k - 1] : ht[1][k + len - 1];
				ck2 = hs[j][1] * B[k];
				if(ck1 != ck2) continue;
				ans ++;
			}
//			cerr << "j , ans = " << j << " " << ans << endl;
		}
		cout << ans << "\n";
	}
	return 0;
} 
