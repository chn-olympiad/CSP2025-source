#include <cstdio>
#include <queue>
#define rep(i, j, k) for(int i = (j); i <= ((int)(k)); i++)
#define rrep(i, j, k) for(int i = (j); i >= ((int)(k)); i--)
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 2e6 + 10;
const ll inf = (ll)1 << 62;
struct node{
	int id;
	ll diss;
	bool operator< (const node& y) const{
		return diss > y.diss;
	}
};
int hea[maxn], nxt[maxm], to[maxm], cnt = 0, from[maxm];
ll val[maxm];
ll dis[15][maxn];
ll cost[15];
ll ddd[maxn];
ll ans = inf;
bool isin[maxn], isbuilt[15];

inline int read(void){
	int ans = 0;
	int ff = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans * ff;
}

inline int readll(void){
	ll ans = 0;
	ll ff = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans * ff;
}

inline void add(int u, int v, ll vall){
	nxt[++cnt] = hea[u];
	hea[u] = cnt;
	from[cnt] = u;
	to[cnt] = v;
	val[cnt] = vall;
}

inline ll scs(int n, int k){
	priority_queue<node> q;
	rep(i, 1, n){
		ddd[i] = inf;
		isin[i] = 0;
	}
	q.push({1, 0});
	ddd[1] = 0;
	int ii;
	ll ans = 0;
	int sum = 0;
	while(sum < n){
		ii = q.top().id;
		if(isin[ii]){
			q.pop();
			continue;
		}
		ans = ans + q.top().diss;
		isin[ii] = 1;
		sum++;
		q.pop();
		for(int j = hea[ii]; j; j = nxt[j]){
			if(!isin[to[j]] && val[j] < ddd[to[j]]){
				q.push({to[j], val[j]});
				ddd[to[j]] = val[j];
			}
		}
		rep(i, 1, k){
			if(isbuilt[i]){
				rep(j, 1, n){
					if(!isin[j] && dis[i][ii] + dis[i][j] < ddd[j]){
						q.push({j, dis[i][ii] + dis[i][j]});
						ddd[j] = dis[i][ii] + dis[i][j];
					}
				}
			}
		}
	}
	return ans;
}

inline void work(int i, int n, int k, ll ext){
	if(i > k){
		ll tt = scs(n, k);
		ans = ans < tt + ext ? ans : tt + ext;
		return;
	}
	work(i + 1, n, k, ext);
	ext += cost[i];
	isbuilt[i] = 1;
	work(i + 1, n, k, ext);
	isbuilt[i] = 0;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = read(), m = read(), k = read();
	int x, y;
	ll vall;
	rep(i, 1, m){
		x = read();
		y = read();
		vall = readll();
		add(x, y, vall);
		add(y, x, vall);
	}
	rep(i, 1, k){
		cost[i] = readll();
		rep(j, 1, n){
			dis[i][j] = readll();
		}
	}
	work(1, n, k, 0);
	printf("%lld\n", ans);
	return 0;
}
