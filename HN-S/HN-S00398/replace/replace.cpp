#include <bits/stdc++.h>
#define rep(i, x,y) for(int i = x; i <= y;i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
//#define int long long
using namespace std;

const int MAXN = 2e5 + 5, MAXL = 5e6 + 5;

int n, q;

string s1[MAXN], s2[MAXN];
string t1[MAXN], t2[MAXN];

const int base = 233, mod = 998244853;

int h1[MAXN], h2[MAXN], pw[MAXN];
unordered_map<int, unordered_map<int, int>> mp;
int gethash1(int l, int r){
	return (h1[r] - 1ll * h1[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

int gethash2(int l, int r){
	return (h2[r] - 1ll * h2[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	pw[0] = 1;
	rep(i, 1, n) pw[i] = pw[i - 1] * base % mod; 
	rep(i, 1, n){
		cin >> s1[i] >> s2[i];
		int hs = 0;
		rep(j ,0, s1[i].size() - 1){
			hs = (1ll * hs * base + s1[i][j]) % mod;
		}
		int hs2 = 0;
		rep(j ,0, s2[i].size() - 1){
			hs2 = (1ll * hs2 * base + s2[i][j]) % mod;
		}
		mp[hs][hs2]++;
//		if(i == 1) cout << hs << ' ' << hs2 << '\n';
	}
	rep(i, 1, q){
		cin >> t1[i] >> t2[i];
		int mxl = -1, len = t1[i].size();
		rep(j, 0, len - 1){
			if(j){
				h1[j] = (1ll * h1[j - 1] * base + t1[i][j]) % mod;
			}else{
				h1[j]=t1[i][j];
			}
		}
		rep(j, 0, len - 1){
			if(j){
				h2[j] = (1ll * h2[j - 1] * base + t2[i][j]) % mod;
			}else{
				h2[j]=t2[i][j];
			}
		}
		for(int j = 0; j < len; j++){
			if(t1[i][j] != t2[i][j]) break;
			mxl = j;
		}
		
		int ans=0;
		for(int j = len - 1; j >= 0; j--){
			rep(k, 0, min(j, mxl + 1)){
				ans += mp[gethash1(k, j)][gethash2(k, j)];
			}
			if(t2[i][j] != t1[i][j]) break;
		}
		// 530868903 530977947
		cout << ans << '\n';
	}
	return 0;
}
