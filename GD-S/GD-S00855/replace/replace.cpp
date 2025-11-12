//T3()
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int N = 200010, M = 5000010, B = 31;
const ll mod = 1e9 + 9;//¼ÇµÃ¿ª__int128£¡£¡£¡ 

ll fpow(ll x, int k){
	if (!k)
		return 1;
	ll t = fpow(x, k >> 1);
	if (k & 1)
		return (__int128)t * t % mod * x % mod;
	return (__int128)t * t % mod; 
}
ll mmi(ll x){
	return fpow(x, mod - 2);
} 

int n, Q, len[N], st[N], ed[N];
ll hsh1[N], hsh2[N];
ll pw[M], inv[M], INV;
ll pre1[M], pre2[M];
char c1[M], c2[M];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(0);
	
	pw[0] = inv[0] = 1, INV = mmi(B);
	for (int i = 1; i <= M; i++){
		pw[i] = (__int128)pw[i - 1] * B % mod;
		inv[i] = (__int128)inv[i - 1] * INV % mod;
	}
	
	cin >> n >> Q;
	for (int i = 1; i <= n; i++){
		cin >> c1 + 1 >> c2 + 1;
		len[i] = strlen(c1 + 1);
		
		st[i] = 0, ed[i] = len[i];
		for (int i = 1; i <= len[i]; i++){
			if (c1[i] != c2[i])
				break;
			st[i]++;
		}
		if (st[i] == len[i]){
			st[i] = -1;
			continue;
		}
		for (int i = len[i]; i >= 1; i--){
			if (c1[i] != c2[i])
				break;
			ed[i]--;
		}
		for (int i = 1; i <= len[i]; i++){
			hsh1[i] = (hsh1[i - 1] + (c1[i] - 'a' + 1) * pw[i - 1]) % mod;
			hsh2[i] = (hsh2[i - 1] + (c2[i] - 'a' + 1) * pw[i - 1]) % mod;
		}
	}
	for (int it = 1; it <= n; it++){
		cin >> c1 + 1 >> c2 + 1;
		int m = strlen(c1 + 1);
		if (m != strlen(c2 + 1)){
			cout << "0\n";
			continue;
		}
		
		int pos1 = 0, pos2 = m, ans = 0;
		for (int i = 1; i <= m; i++){
			if (c1[i] != c2[i])
				continue;
			pos1++;
		}
		for (int i = m; i >= 1; i--){
			if (c1[i] != c2[i])
				continue;
			pos2--;
		}
		
		for (int i = 1; i <= m; i++){
			pre1[i] = (pre1[i - 1] + (c1[i] - 'a' + 1) * pw[i - 1]) % mod;
			pre2[i] = (pre2[i - 1] + (c2[i] - 'a' + 1) * pw[i - 1]) % mod;
		}
		for (int i = 1; i <= n; i++){
			if (st[i] == -1)
				continue;
			if (pos2 + len[i] - ed[i] <= m && hsh1[i] == pre1[pos2 + 1]){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
