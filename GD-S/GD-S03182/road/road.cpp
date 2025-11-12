#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,int>;
const int N = 1e4 + 5,M = 1e6 + 5,K = 15;
int n,m,k,tot,cnt;
int fa[N],head[N],nxt[2 * M],to[2 * M];
ll ans;
ll crr[K],arr[K][N],dis[K][N],val[2 * M];
bool vis[K][N];
struct edge{
	int fr,to;
	ll w;
	inline bool operator <(const edge& ed)const{
		return w < ed.w;
	}
}e[2 * M];
inline ll read(){//>=0
	ll x = 0;char c = getchar();
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x<<1) + (x<<3) + (c^48);
		c = getchar();
	}
	return x;
}
inline void add(ll a,ll b,ll w){
	//ksc
	e[++tot].fr = a;
	e[tot].to = b;
	e[tot].w = w;
	//dijstr
	nxt[++cnt] = head[a];
	to[cnt] = b;
	val[cnt] = w;
	head[a] = cnt;
	return ;
}
inline int found(int x){
	if(fa[x] != x){
		fa[x] = found(fa[x]);
	}
	return fa[x];
}
inline void merge(int x,int y){
	x = found(x);
	y = found(y);
	fa[x] = y;
	return ;
}
void Kruscal(){
	sort(e + 1,e + 1 + tot);
	int cnt = 1,a,b;//total n-1 edges
	for(int i = 1; i <= tot && cnt < n; ++i){
		a = found(e[i].fr);
		b = found(e[i].to);
		if(a == b) continue;
		ans += e[i].w;
		merge(a,b);
		++cnt;
	}
//	printf("real : %lld\n",ans);
	return ;
}
void dijstra(int st){
	priority_queue<pii,vector<pii>,greater<pii> > q;//small
	q.push({0,st});
	dis[st][st] = 0;
	int id;
	while(!q.empty()){
		id = q.top().second;
		q.pop();
		if(vis[st][id]) continue;
		vis[st][id] = true;
//		printf("id : %d\n",id);
		for(int i = head[id],t; i; i = nxt[i]){
			t = to[i];
//			printf("%d --> %d\n",id,t);
			if(dis[st][t] > dis[st][id] + val[i]){
				dis[st][t] = dis[st][id] + val[i];
				if(!vis[st][t]){
					q.push({dis[st][t],t});
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();m = read();k = read();
	ll a,b,w;
	for(int i = 1; i <= m; ++i){
		a = read();
		b = read();
		w = read();
		add(a,b,w);
		add(b,a,w);
	}
	bool SP_A = true;
	for(int i = 1; i <= k; ++i){
		crr[i] = read();
		if(crr[i]) SP_A = false;
		for(int j = 1; j <= n; ++j){
			arr[i][j] = read();
			if(arr[i][j]) SP_A = false;
		}
	}
	
	if(SP_A){//special_A for all choose c_j,then cost 0 yuan 
		printf("0");
		return 0;
	}
	//real
	for(int i = 1; i <= n; ++i){
		fa[i] = i;
	}
	Kruscal();//O(n + m)
	if(k == 0){//tps: 1~4
		printf("%lld",ans);
		return 0;
	}
//	memset(dis,0x3f,sizeof(dis));
//	for(int i = 1; i <= k; ++i){//O(knlogn) => 1 200 000 => 1e6
//		dijstra(i);
//		printf("dis , from %d :\n",i);
//		for(int j = 1; j <= n; ++j){
//			printf("%lld ",dis[i][j]);
//		}
//		printf("\n");
//	}
	
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
