#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define fi first
#define se second
#define mst(f, i) memset(f, i, sizeof f)
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr);
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
namespace fastio{
	template<typename T> inline void read(T &t){
		T x = 0, f = 1;
		char c = getchar();
		while(!isdigit(c)){
			if(c == '-') f = -f;
			c = getchar();
		}
		while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
		t = x * f;
	}
	template<typename T, typename ... Args> inline void read(T &t, Args &...args){
		read(t), read(args...);
	}
	void write(int x){printf("%d", x);}
	void writes(int x){printf("%d ", x);}
	void writeln(int x){printf("%d\n", x);}
	void write(ll x){printf("%lld", x);}
	void writes(ll x){printf("%lld ", x);}
	void writeln(ll x){printf("%lld\n", x);}
}
using namespace fastio;
#define multitest() int T; read(T); for(int tCase = 1; tCase <= T; ++tCase)
const int N = 1e5 + 5, inf = 0x3f3f3f3f;
ll n, a[N][3];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	multitest(){
		read(n);
		ll ans = 0;
		vector<int> vt[3];
		_rep(i, 1, n){
			ll maxn = -1, id = -1;
			_rep(j, 0, 2) read(a[i][j]), id = a[i][j] > maxn ? j : id, maxn = max(maxn, a[i][j]);
//			_rep(j, 0, 2) debug("%lld ", a[i][j]); debug("\n");
			vt[id].pb(i), ans += maxn;
//			debug("i:%d id:%d\n", i, id);
		}
//		debug("eee %lld\n", ans);
		_rep(i, 0, 2){
			if(vt[i].size() <= n / 2) continue;
//			debug("i:%d %d\n", i, vt[i].size());
			priority_queue<ll> q;
			for(auto &j : vt[i]){
				ll maxn = -inf;
				_rep(k, 0, 2) if(k != i) maxn = max(maxn, a[j][k] - a[j][i]);
				q.push(maxn);
			} 
			int t = (int)vt[i].size() - n / 2;
			_rep(j, 1, t) ans += q.top(), q.pop(); 
		}
		writeln(ans);
//		debug("================\n");
	}
	return 0;
}

