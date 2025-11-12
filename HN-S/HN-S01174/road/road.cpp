#include<bits/stdc++.h>
#define pii pair<int,int>
#define vti vector<int>
#define psbk push_back
#define fi first
#define se second

using namespace std;
const int N=10005,INF=0x3f3f3f3f;
int n,m,k,u,v,w,f[N],an,c[N],a[15][N];
priority_queue<pii> e[N];
vti xx[15];
void sveA(){
	for(int i=1;i<=k;i++){
		if(c[i]) return ;
		bool t=0;
		for(int j=1;j<=n;j++) if(!a[i][j]) t=1,xx[i].psbk(j);
		if(!t) return ;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int x=0;x<xx[i].size();x++){
				if(xx[i][x]==j) continue;
				e[xx[i][x]].push({a[i][j],j});
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
		e[u].push({w,v}),e[v].push({w,u});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sveA();
	f[1]=1;
	for(int i=1;i<n;i++){
		int mi=INF,id;
		for(int j=1;j<=n;j++){
			if(!f[j]) continue;
			while(!e[j].empty()&&f[e[j].top().se]) e[j].pop();
			if(!e[j].empty()&&e[j].top().fi<mi){
				mi=e[j].top().fi;
				id=j;
			}
		}
		if(mi!=INF){
			an+=mi;
			f[e[id].top().se]=1;
			e[id].pop();
		}
	}
	cout<<an;
	return 0;
}/*
3 3 0
1 2 1
1 3 2
2 3 3
*/
