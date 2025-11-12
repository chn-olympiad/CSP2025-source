#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long inf = 1e18 + 10;
inline int read(){int x = 0, f = 1; char ch = getchar();while(ch > '9' or ch < '0'){if(ch == '-'){f = -1;}ch=getchar();}while(ch >= '0' and ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}return x * f;}
inline void write(int x){if(x < 0){putchar('-');x = -x;}if(x >= 10){write(x/10);}putchar(x % 10 + '0');}
#define pb emplace_back
#define put() putchar(' ')
#define endl puts("")
const int MAX = 2e4 + 10;
const int MAX2 = 1e6 + 10;
// const int MAX2 =

struct node{
	int u, v, w;
	bool operator < (const node &x) const{
		return w > x.w;
	}
}; node g[MAX2];

bool cmp(node x, node y){
	return x.w < y.w;
}

int c[MAX];
pair <int, int> c2[MAX];
int a[20][MAX];
int bcj[MAX];
int find(int x){
	if(bcj[x] == x)	return x;
	return bcj[x] = find(bcj[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x < y)	swap(x, y);
	bcj[x] = y;
}

namespace solve1{
	void solve(int n, int m, int k){
		for(int i = 1; i <= m; i++){
			// int u = read(), v = read(), w = read();
			g[i].u = read(), g[i].v = read(), g[i].w = read();
		}
		sort(g + 1, g + m + 1, cmp);
		// for(int i = 1; i <= m; i++){
			// write(g[i].w), put();
			// endl;
		// }
		for(int i = 1; i <= k; i++){
			c[i] = read();
			c2[i].first = c[i], c2[i].second = i;
			for(int j = 1; j <= n; j++){
				a[i][j] = read();
			}
		}
		sort(c2 + 1, c2 + k + 1);
		int ans = inf;
		int baseee = 1;
		baseee = (1ll << k) - 1;
		for(int i = baseee; i < (1ll << k); i++){
			int n2 = n;
			int cnt = 0;
			priority_queue <node> q;
			for(int j = 1; j <= k; j++){
				if(i & (1ll << (j - 1))){
					n2++;
					cnt += c[j];
					for(int k2 = 1; k2 <= n; k2++){
						q.push(node{n + j, k2, a[j][k2]});
					}
				}
			}
			// write(cnt), endl;
			for(int j = 1; j <= n + k; j++){
				bcj[j] = j;
			}
			int cnt2 = n2 - 1;
			// int cntt = 0;
			for(int j = 1; j <= m; j++){
				// cntt ++;
				while(!q.empty() and q.top().w < g[j].w){
					// cntt++;
					node x = q.top();
					q.pop();
					if(find(x.u) == find(x.v))	continue;
					cnt += x.w;
					merge(x.u, x.v);
					cnt2--;
					if(cnt2 == 0)	break;
				}
				if(cnt2 == 0)	break;
				if(find(g[j].u) == find(g[j].v))	continue;
				cnt += g[j].w;
				merge(g[j].u, g[j].v);
				cnt2--;
				if(cnt2 == 0)	break;
			}
			// for(int j = 1; j <= n; j++)	write(find(j)), put();
			// endl;
			// write(cnt2), endl;
			// write(cntt), endl;
			ans = min(ans, cnt);
		}	
		
		sort(c + 1, c + k + 1);
		// write(ans), endl;
		int now = (1ll << k) - 1;
		// write(n), put(), write(m), put(), write(k), endl;
		// write(ans), endl;
		for(int newii = k; newii >= 1; newii--){
			// write(ii), endl;
			int i = now - (1ll << (c2[newii].second - 1));
			// write(I
			// write(i), endl;
			int n2 = n;
			int cnt = 0;
			priority_queue <node> q;
			for(int j = 1; j <= k; j++){
				if(i & (1ll << (j - 1))){
					n2++;
					cnt += c[j];
					for(int k2 = 1; k2 <= n; k2++){
						q.push(node{n + j, k2, a[j][k2]});
					}
				}
			}
			// write(cnt), endl;
			for(int j = 1; j <= n + k; j++){
				bcj[j] = j;
			}
			int cnt2 = n2 - 1;
			// int cntt = 0;
			for(int j = 1; j <= m; j++){
				// cntt ++;
				while(!q.empty() and q.top().w < g[j].w){
					// cntt++;
					node x = q.top();
					q.pop();
					if(find(x.u) == find(x.v))	continue;
					cnt += x.w;
					merge(x.u, x.v);
					cnt2--;
					if(cnt2 == 0)	break;
				}
				if(cnt2 == 0)	break;
				if(find(g[j].u) == find(g[j].v))	continue;
				cnt += g[j].w;
				merge(g[j].u, g[j].v);
				cnt2--;
				if(cnt2 == 0)	break;
			}
			if(ans >= cnt){
				now = i;
				// write(i), put(), write(cnt), endl;
				ans = cnt;
			}
			// ans = min(ans, cnt);
		}
		// write(now), endl;
		write(ans), endl;
	}
}

namespace solve2{
	void solve(int n, int m, int k){
		for(int i = 1; i <= m; i++){
			// int u = read(), v = read(), w = read();
			g[i].u = read(), g[i].v = read(), g[i].w = read();
		}
		sort(g + 1, g + m + 1, cmp);
		// for(int i = 1; i <= m; i++){
			// write(g[i].w), put();
			// endl;
		// }
		for(int i = 1; i <= k; i++){
			c[i] = read();
			for(int j = 1; j <= n; j++){
				a[i][j] = read();
			}
		}
		int ans = inf;
		for(int i = 0; i < (1ll << k); i++){
			int n2 = n;
			int cnt = 0;
			priority_queue <node> q;
			for(int j = 1; j <= k; j++){
				if(i & (1ll << (j - 1))){
					n2++;
					cnt += c[j];
					for(int k2 = 1; k2 <= n; k2++){
						q.push(node{n + j, k2, a[j][k2]});
					}
				}
			}
			// write(cnt), endl;
			for(int j = 1; j <= n + k; j++){
				bcj[j] = j;
			}
			int cnt2 = n2 - 1;
			// int cntt = 0;
			for(int j = 1; j <= m; j++){
				// cntt ++;
				while(!q.empty() and q.top().w < g[j].w){
					// cntt++;
					node x = q.top();
					q.pop();
					if(find(x.u) == find(x.v))	continue;
					cnt += x.w;
					merge(x.u, x.v);
					cnt2--;
					if(cnt2 == 0)	break;
				}
				if(cnt2 == 0)	break;
				if(find(g[j].u) == find(g[j].v))	continue;
				cnt += g[j].w;
				merge(g[j].u, g[j].v);
				cnt2--;
				if(cnt2 == 0)	break;
			}
			// for(int j = 1; j <= n; j++)	write(find(j)), put();
			// endl;
			// write(cnt2), endl;
			// write(cntt), endl;
			ans = min(ans, cnt);
			// if(i == 1013){
				// putchar('a'),write(cnt), endl;
			// }
		}
		write(ans), endl;
	}
}


signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = read(), m = read(), k = read();
	// solve2::solve(n, m, k);
	// solve1::solve(n, m, k);
	if(k <= 5)	solve2::solve(n, m, k);
	else solve1::solve(n, m, k);
	return 0;
}