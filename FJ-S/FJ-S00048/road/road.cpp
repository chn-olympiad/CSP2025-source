#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 1e5;
int h[MAXN] = {};
int fa[MAXN] = {};

int find(int t){
	if(t == fa[t]) return t;
	else return fa[t] = find(fa[t]);
}

struct road{
	int u, v, w;
}roads[1000005] = {};

int visit[1005][1005] = {};
int q[15][1005] = {};
bool dis[1005][1005] = {};

int min(int a, int b){
	return a<b?a:b;
}

bool cmp(road a, road b){
	return a.w==b.w?a.u<b.u:a.w<b.w;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			visit[i][j] = 2147483647;
		}
	}
	for(int i = 1; i<=m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		visit[a][b] = c;
		visit[b][a] = c;
	}
	for(int i = 1; i<=k; i++){
		for(int j = 0; j<=n; j++){
			scanf("%d", &q[i][j]);
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++){
			int minn = visit[i][j];
			for(int b = 1; b<=k; b++){
				int t = q[b][i]+q[b][j]+q[b][0];
				if(t < minn) minn = t;
			}
			visit[i][j] = minn;
			visit[j][i] = visit[i][j];
		}
	}

	int now = 1;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			roads[now].u = i, roads[now].v = j, roads[now].w = visit[i][j];
			now++;
		}
	}
	sort(roads+1, roads+now, cmp);
	
	
	for(int i = 1; i<=n; i++){
		fa[i] = i;
	}
	
	int ans = 0;
	for(int i = 1; i<=now-1; i++){
		int u = roads[i].u, v = roads[i].v, w = roads[i].w;
		if(find(u) != find(v)){
			int a = find(u);
			int b = find(v);
			fa[a] = b;
			ans+=w;
		}
	}
	printf("%d", ans);
	return 0;
}
