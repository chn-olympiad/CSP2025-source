# include <bits/stdc++.h>
# define pb push_back
# define int long long
# define pii pair <int, int>
# define fi first
# define se second
using namespace std;

const int N = 2e5 + 5, L = 5e6 + 5, mod = 998244353, ny = 576923081;

int n, q, pw[L], ans[N], npw[L], bl[L], br[L];

char s[L], t[L];

struct node{
	int m, sm, lx, lz, x, z;
	vector <int> vl, vr;
} S[N], T[N];

bool cmp(node a, node b){return a.sm < b.sm;}

map <int, pii> mp1, mp2;

signed main(){
//	freopen("replace3.in",  "r", stdin);
//	freopen("my.txt", "w", stdout);
	freopen("replace.in",  "r", stdin);
	freopen("replace.out", "w", stdout);
	pw[0] = npw[0] = 1;
	for (int i = 1;i < N;i++) pw[i] = pw[i-1] * 26 % mod, npw[i] = npw[i-1] * ny % mod;
	scanf("%lld%lld", &n, &q);
	for (int i = 1;i <= n;i++){
		scanf("%s%s", s+1, t+1);
		int m = strlen(s+1), l = 0, r = 0, sx = 0, sy = 0, sz = 0, ty = 0;
		for (int j = 1;j <= m;j++) if (s[j] != t[j]){
			if (l == 0) l = j;
			r = j;
		}
		for (int j = 1;j < l;j++) sx = (sx*26 + (s[j]-'a'+1)) % mod;
		for (int j = l;j <= r;j++) sy = (sy*26 + (s[j]-'a'+1)) % mod;
		for (int j = l;j <= r;j++) ty = (ty*26 + (t[j]-'a'+1)) % mod;
		for (int j = m;j >= r+1;j--) sz = (sz*26 + (s[j]-'a'+1)) % mod;
		S[i].m = m; S[i].sm = (sy*pw[r-l+1] + ty) % mod;
		S[i].lx = l-1; S[i].lz = m-r; S[i].x = sx; S[i].z = sz;
//		mp1[(sy*pw[r-l+1] + ty) % mod] = {sx, sz};
	}
	for (int i = 1;i <= q;i++){
		scanf("%s%s", s+1, t+1);
		int m = strlen(s+1), mt = strlen(t+1), l = 0, r = 0, sx = 0, sy = 0, sz = 0, ty = 0;
		if (m != mt){
			ans[i] = 0;
			T[i] = (node){i, 0, 0, 0, 0, 0};
			continue;
		}
		for (int j = 1;j <= m;j++) if (s[j] != t[j]){
			if (l == 0) l = j;
			r = j;
		}
		for (int j = 1;j < l;j++) T[i].vl.pb(s[j]-'a'+1), sx = (sx*26 + (s[j]-'a'+1)) % mod;
		for (int j = l;j <= r;j++) sy = (sy*26 + (s[j]-'a'+1)) % mod;
		for (int j = l;j <= r;j++) ty = (ty*26 + (t[j]-'a'+1)) % mod;
		for (int j = m;j >= r+1;j--) T[i].vr.pb(s[j]-'a'+1), sz = (sz*26 + (s[j]-'a'+1)) % mod;
		reverse(T[i].vr.begin(), T[i].vr.end());
		T[i].m = i; T[i].sm = (sy*pw[r-l+1] + ty) % mod;
		T[i].lx = l-1; T[i].lz = m-r; T[i].x = sx; T[i].z = sz;
//		printf("%2lld %2lld %5lld\n", T[i].lx, T[i].lz, T[i].z);
//		mp1[(sy*pw[r-l+1] + ty) % mod] = {sx, sz};
	}
	sort (S+1, S+n+1, cmp); sort (T+1, T+q+1, cmp);
//	for (int i = 1;i <= n;i++) printf("%2lld %2lld %5lld %5lld %5lld\n", S[i].lx, S[i].lz, S[i].x, S[i].z, S[i].sm);
//	for (int i = 1;i <= q;i++) printf("%2lld %2lld %5lld %5lld %5lld\n", T[i].lx, T[i].lz, T[i].x, T[i].z, T[i].sm);
	int lt = 1, rt = 0;
	while (lt <= q && T[lt].sm == 0) lt++;
	for (int ls = 1, rs = 1;ls <= n;ls = rs+1){
		rs = ls;
		while (rs+1 <= n && S[rs+1].sm == S[ls].sm) rs++;
		while (lt+1 <= q && T[lt].sm < S[ls].sm) lt++; rt = lt;
		while (rt+1 <= q && T[rt+1].sm == S[ls].sm) rt++;
		if (T[lt].sm != S[ls].sm) continue;
		for (int j = lt;j <= rt;j++){
			bl[0] = br[0] = 0; bl[T[j].lx+1] = 0;
//			for (int i : T[j].vl) printf("%lld ", i); puts("");
//			for (int i : T[j].vr) printf("%lld ", i); puts("");
//			puts("--");
			for (int i = T[j].lx;i >= 1;i--) bl[i] = (bl[i+1] + T[j].vl[i-1] * pw[T[j].lx-i]) % mod;
			for (int i = 1;i <= T[j].lz;i++) br[i] = (br[i-1] + T[j].vr[i-1] * pw[i-1]) % mod;
//			for (int i = 0;i <= T[j].lx;i++) printf("%5lld ", bl[i]); puts("");
//			for (int i = 0;i <= T[j].lz;i++) printf("%5lld ", br[i]); puts("");
			for (int i = ls;i <= rs;i++){
				
				if (S[i].lx <= T[j].lx && S[i].lz <= T[j].lz){
					if (S[i].x == (bl[T[j].lx - S[i].lx + 1] + mod) % mod && S[i].z == (br[S[i].lz] + mod) % mod){
						ans[T[j].m]++;
//						printf("[%lld]\n", i);
					}
//						printf("[%lld]\n", i);
				}
				
			}
		}
	}
	for (int i = 1;i <= q;i++) printf("%lld\n", ans[i]);
	return 0;
}

