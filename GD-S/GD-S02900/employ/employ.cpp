#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LL long long
typedef pair<int, int> PII;
LL read(){LL x; scanf("%lld", &x); return x; }

const int N = 510;
const int mod = 998244353;
const int S = 3e5 + 10;

int fac[N * 2], inv[N * 2];
int qpw(int d, int u){
	int res = 1;
	while(u){
		if(u & 1)res = res * d % mod;
		d = d * d % mod; u >>= 1;		
	}
	return res;
}
int A(int x, int y){return y > x ? 0 : fac[x] * inv[x - y] % mod; }
int C(int x, int y){return A(x, y) * inv[y] % mod; }
void pre(){
	fac[0] = 1;
	for(int i = 1; i <= N * 2 - 5; i ++)fac[i] = fac[i - 1] * i % mod, inv[i] = qpw(fac[i], mod - 2);
}

string str;

int n, m;
int s[N];
int c[N];

int pv[N], le;
int va[N];
int f[N][N];

int g[N];
void add(int &x, int y){x += y; x %= mod; }

void solve(int qid){
	pre();
	
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> str;
	for(int i = 1; i <= n; i ++)s[i] = str[i - 1] - '0';
	for(int i = 1; i <= n; i ++)c[i] = read(), va[c[i]] ++;
	
	for(int i = 1; i <= n; i ++)va[i] += va[i - 1];
	int ct0 = 0; 
	for(int i = 1; i <= n; i ++){
		if(s[i])pv[++ le] = ct0;
		else ct0 ++;
	}

	if(ct0 == 0){
		int gta = 1;
		for(int i = 1; i <= n; i ++)gta = gta * i % mod;
		printf("%lld", gta);
		return ;	
	}
	
	f[0][0] = 1;
	for(int i = 0; i < le; i ++){
		for(int j = 0; j <= i; j ++){
			add(f[i + 1][j], f[i][j]);
			for(int k = j + 1; j <= i + 1; j ++){
				int nd = k - (j + 1), tv = f[i][j] * (va[pv[i + 1] + k] - j) % mod;
				tv = tv * C(va[pv[i + 1] + k] - va[pv[i] + j] - 1, nd) % mod * A(i + 1 - k, nd) % mod;
				add(f[i + 1][k], tv);
			}
		}
	}
	for(int i = 1; i <= le; i ++)
		g[i] = f[le][i] * C(va[n] - va[pv[le] + i], le - i) % mod * A(le - i, le - i) % mod;
	
	int ans = 0;
	for(int i = m; i <= le; i ++)
		if(le - m >= 0)ans = (ans + g[le - m]) % mod;
	ans = ans * fac[ct0] % mod;
	printf("%lld", ans);
}

signed main(){
    int tii = 1;
    for(int z = 1; z <= tii; z ++)solve(z);
    return 0;
}
