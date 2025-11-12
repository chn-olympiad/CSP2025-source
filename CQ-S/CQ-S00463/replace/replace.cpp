#include <bits/stdc++.h>
#define re register
#define int long long

using namespace std;

const int N = 2e5 + 10,M = 4010;
const int K = 5e6 + 10,L = 1e9;
const int base = 131;
const int mod = 102401027;
int n,q;
int pw[K],invpw[K],hs[K];
vector<int> Lens;
unordered_map<int,int> mp;

inline int qmi(int a,int b){
	int res = 1;
	while (b){
		if (b & 1) (res *= a) %= mod;
		(a *= a) %= mod; b >>= 1;
	} return res;
}

inline void init(int n){
	const int Inv = qmi(base,mod - 2);
	pw[0] = 1,invpw[0] = 1;
	for (re int i = 1;i <= n;i++) pw[i] = pw[i - 1] * base % mod;
	for (re int i = 1;i <= n;i++) invpw[i] = invpw[i - 1] * Inv % mod;
}

inline int geths(int l,int r){ return (hs[r] - hs[l - 1] * pw[r - l + 1] % mod + mod) % mod; }

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q; init(5e6);
	for (re int i = 1;i <= n;i++){
		string t[2];
		cin >> t[0] >> t[1];
		int hs1 = 0,hs2 = 0;
		for (char c:t[0]) hs1 = (hs1 * base + c) % mod;
		for (char c:t[1]) hs2 = (hs2 * base + c) % mod;
		mp[hs1 * L + hs2]++;
		Lens.push_back(t[0].size());
	} sort(Lens.begin(),Lens.end());
	Lens.erase(unique(Lens.begin(),Lens.end()),Lens.end());
	while (q--){
		int ans = 0;
		string s,ss;
		cin >> s >> ss;
		if (s.size() != ss.size()){ cout << "0\n"; continue; }
		int lens = s.size();
		s = ' ' + s,ss = ' ' + ss;
		int be = 0,ed = 0,fhs = 0;
		for (re int i = 1;i <= lens;i++){
			if (s[i] != ss[i]){ be = i; break; }
		}
		for (re int i = lens;i;i--){
			if (s[i] != ss[i]){ ed = i; break; }
		}
		for (re int i = 1;i <= lens;i++) fhs = (fhs * base + ss[i]) % mod;
		for (re int i = 1;i <= lens;i++) hs[i] = (hs[i - 1] * base + s[i]) % mod;
		for (int len:Lens){
			if (len < ed - be + 1) continue;
			if (len > s.size()) break;
//			cerr << len << " ???\n";
			for (re int i = max(1ll,ed - len + 1),j = i + len - 1;j <= min(be + len - 1,lens);i++,j++){
				int a = geths(i,j);
				int b = (fhs - (hs[lens] - a * pw[lens - j] % mod) + mod) * invpw[lens - j] % mod;
//				cerr << i << " " << j << " " << a << " " << b << " " << (fhs - tmp + mod) % mod << " replace\n";
				ans += mp[a * L + b];
			}
		} cout << ans << "\n";
		
	}
	return 0;
}

/*
no scanf, printf, puts, putchar and so on!!!

4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex

你说得对，但是 n sqrt(L) 真的能过吗 /yun 
*/
