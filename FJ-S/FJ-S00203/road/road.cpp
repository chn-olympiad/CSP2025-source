#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N = 1e4+15;
const int MAX_M = 1e6+10*MAX_N;

struct Edge{
	int u, v, w;
}vis[MAX_M], nvis[MAX_M];

int n, m, k, f[MAX_N], c[15][MAX_N], ans, minans = 0x3f3f3f3f;

int gf(int u){
	return u == f[u]? u : f[u] = gf(f[u]);
}

bool cmp(Edge a, Edge b){
	return a.w < b.w;
}

signed main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &vis[i].u, &vis[i].v, &vis[i].w);
	}
	for(int i = 0; i < k; i++){
		for(int j = 0; j <= n; j++){
			scanf("%d", &c[i][j]);
		}
	}
	
	int mik = 1<<k;
	for(int i = 0; i < mik; i++){
		ans = 0;
		for(int j = 1; j <= m; j++){
			nvis[j].u = vis[j].u;
			nvis[j].v = vis[j].v;
			nvis[j].w = vis[j].w;
		}
		int cnt = m, cnt2 = n;
		for(int j = 0; j < k; j++){
			if(! (i & (1<<j))){
				continue;
			}
			cnt2++;
			ans += c[j][0];
			for(int kv = 1; kv <= n; kv++){
				cnt++;
				nvis[cnt].u = kv;
				nvis[cnt].v = j+n+1;
				nvis[cnt].w = c[j][kv];
			}
		}
		for(int j = 1; j <= n+k; j++){
			f[j] = j;
		}
		sort(nvis+1, nvis+cnt+1, cmp);
		//cout<<i<<' '<<cnt<<' '<<cnt2<<":\n";
		//for(int j = 1; j <= cnt; j++){
		//	printf("%d %d %d\n",nvis[j].u,nvis[j].v,nvis[j].w);
		//}
		int flag = 1;
		for(int j = 1; j <= cnt; j++){
			if(gf(nvis[j].u) != gf(nvis[j].v)){//printf("%d*%d~%d\n", i, nvis[j].u,nvis[j].v);
				f[nvis[j].u] = nvis[j].v;
				flag++;
				ans += nvis[j].w;
			}
			if(flag == cnt2){
				break;
			}
		}
		minans = min(ans, minans);
	}
	
	printf("%d", minans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
