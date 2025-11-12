#include<bits/stdc++.h>
#define pii pair <int, int>
#define LL long long
using namespace std;
int read(){
	int s = 0, f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}
	while(isdigit(ch)){s = s * 10 + ch - '0';ch = getchar();}
	return s * f;
}
const int MAXN = 1e4 + 15, MR = 3e6 + 5;
const LL INF = 1e16;
struct edge{
	int from, to, len, nxt;
}e[MR];
int n, m, k, tp, cnt, head[MAXN], c[15], used[MAXN], vis[MAXN], dis[MAXN];
LL ans;
void add_edge(int u, int v, int w){
	e[++ cnt] = {u, v, w, head[u]};
	head[u] = cnt;
}
LL prim(int op){
	LL res = 0;
	priority_queue <pii, vector <pii>, greater <pii> > pq;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	pq.push({0, 1});
	while(!pq.empty()){
		auto tmp = pq.top();
		int h = tmp.second;
		pq.pop();
		tp ++;
		if(!used[h] || vis[h])continue;
//		printf("%lld %lld\n", h, tmp.len);
		res += tmp.first, vis[h] = 1;
		if(res + op > ans)return res;
		for(int i = head[h];i;i = e[i].nxt){
			int v = e[i].to, w = e[i].len;
			tp ++; 
			if(vis[v] || !used[v])continue;
			if(dis[v] > w)pq.push({w, v}), dis[v] = w;
		}
	}
	return res;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1;i <= m;i ++){
		int u = read(), v = read(), w = read();
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	bool flag = 1;
	for(int i = 1;i <= k;i ++){
		c[i] = read(), flag &= (!c[i]);
		for(int j = 1;j <= n;j ++){
			int x = read();
			add_edge(i + n, j, x);
			add_edge(j, i + n, x);
		}
	}
	ans = INF;
	for(int i = 1;i <= n;i ++)used[i] = 1;
	int t = 30;
	if(k == 10)t = 20;
	srand(time(0));
	while(t --){
		int i = rand() % (1 << k);
		if(flag)i = (1 << k) - 1;
		LL res = 0;
		for(int j = 0;j < k;j ++){
			if((1 << j) & i)used[j + n + 1] = 1, res += c[j + 1];
		}
		ans = min(ans, res + prim(res));
		for(int j = 1;j <= k;j ++)used[j + n] = 0;
		if(flag)break;
	}
	printf("%lld\n", ans); 
	return 0;
}

