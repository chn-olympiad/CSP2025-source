#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
int n,m,k;
int c[N],cntt;
int head[N * 3],Next[N * 3],vv[N * 3],ww[N * 3],cnt;
int l;
inline void add(int u,int v,int w){
	Next[++cnt] = head[u];
	vv[cnt] = v;
	ww[cnt] = w;
	head[u] = cnt;
}
queue<int > q;
int vis[N],viss[N + 20];
ll minn,nxt;
ll ans,sum,nn;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);nn = n;
	for(int i = 1;i <= m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	cntt = n;
	for(int i = 1;i <= k;i++){
		scanf("%d",&c[cntt + i]);
		for(int j = 1;j <= n;j++){
			int w;scanf("%d",&w);
			add(cntt + i,j,w);add(j,cntt + i,w);
		}
	}
	if(k > 0){
		printf("0");
	}
	else{
		q.push(1);vis[1] = 1;
		while(!q.empty()){
			int u = q.front();q.pop();
			minn = 1e9 + 10;
			for(int i = head[u];i;i = Next[i]){
				int v = vv[i],w = ww[i];
				if(vis[v]) continue;
				if(v > n && !viss[v]) w += c[v];
				if(minn == w && l != 0){
					viss[l] = 0;l = 0;
					nxt = v;
				}
				else if(minn > w){
					if(v > n && l == 0) viss[v] = 1,l = v,nn++;
					else{
						if(viss[l] && v <= n){viss[l] = 0;nn--;}
						else if(viss[l] && v > n){viss[l] = 0;viss[v] = 1;l = v;}
					};
					minn = w;
					nxt = v;
				}
			}
			sum++;
			ans += minn;
			if(sum == nn - 1) break;
			q.push(nxt);vis[nxt] = 1;
			l = 0;
		}
		printf("%lld",ans);
	}
	return 0;
} 
