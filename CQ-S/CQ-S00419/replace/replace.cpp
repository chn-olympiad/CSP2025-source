#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long 
#define pii pair<int, int>
#define ull unsigned long long
#define mse(x, y) memset(x, y, sizeof x)
#define mcp(x, y) memcpy(x, y, sizeof x)
#define viclear(x) vector<int>().swap(x)
#define vpiiclear(x) vector<pii>().swap(x)
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define drep(x, r, l) for(int x = r; x >= l; x--)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
using namespace std;

const int MAXN = 2e3 + 5;
const ull BASE = 13331;
int n, q, Len[MAXN];
ull hsh[2][MAXN][MAXN];
ull base[MAXN];
string S1, S2, T1, T2;

ull Get(int x, int l, int r, bool op){ return hsh[op][x][r] - hsh[op][x][l - 1] * base[r - l + 1]; }

void Hash(int x){
	Len[x] = (int)S1.size();
	rep(i, 0, (int)S1.size() - 1){
		hsh[0][x][i + 1] = hsh[0][x][i] * BASE + (ull)S1[i];
		hsh[1][x][i + 1] = hsh[1][x][i] * BASE + (ull)S2[i];
	}
}

void Hasht(int x){
	rep(i, 0, (int)T1.size() - 1){
		hsh[0][x][i + 1] = hsh[0][x][i] * BASE + (ull)T1[i];
		hsh[1][x][i + 1] = hsh[1][x][i] * BASE + (ull)T2[i];
	}
}

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	FASTIO;
	base[0] = 1;
	rep(i, 1, MAXN - 1) base[i] = base[i - 1] * BASE;
	cin >> n >> q;
	rep(i, 1, n){
		cin >> S1 >> S2;
		Hash(i);
	}
	while(q--){
		cin >> T1 >> T2;
		if((int)T1.size() != (int)T2.size()){
			cout << 0 << '\n';
			continue;
		}
		int L = (int)T1.size(), R = -1;
		rep(i, 0, (int)T1.size() - 1) if(T1[i] != T2[i]) L = min(L, i), R = max(R, i); 
		Hasht(n + 1);
		int ans = 0;
		rep(i, 1, n){
			rep(l, 1, (int)T1.size() - Len[i] + 1){
				int r = l + Len[i] - 1;
				if(l > L || r < R) continue;
				if(Get(n + 1, l, r, 0) == Get(i, 1, Len[i], 0) && Get(n + 1, l, r, 1) == Get(i, 1, Len[i], 1) ans++;
			}
		}
		cout << ans << '\n';
	}
    return 0;
}

