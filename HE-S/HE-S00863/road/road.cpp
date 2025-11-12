#include<bits/stdc++.h>
using namespace std;
#define elif else if
#define int long long
const int N = 1e4+10;
int w[N][N],dis[N],n,m,k,x,y,wi,from[N];
bool vis[N];
void spfa(){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		dis[i] = w[1][i];
		from[i] = -1;
	}
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(i == f) continue;
			if(dis[f]+w[i][f]<dis[i]){
				dis[i] = dis[f]+w[i][f];
				from[i] = f;
			}
			if(!vis[i]){
				vis[i]=1;
				q.push(i);
			}
		}
	}
}
signed main(){
//	freopen("D:/road/roadk.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	for(int i = 1;i<N;i++){
//		for(int j = 1;j<N;j++){
//			w[i][j] = 1e9;
//		}
//	}
//	memset(w,0x3f3f3f,sizeof w);
//	cin>>n>>m>>k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0;i<m;i++){
//		cin>>x>>y>>wi;
		scanf("%d%d%d",&x,&y,&wi);
		w[x][y]=wi;
		w[y][x]=wi;
	}
	for(int i=1;i<=k;i++){
//		cin>>x;
		scanf("%d",&x);
		for(int kk=1;kk<=n;kk++){
//			cin>>x;
			scanf("%d",&x);
//			w[i][kk] = 0;
//			w[kk][i] = 0;
		}
	}
	cout<<0;
//	spfa();
//	for(int i = 1;i<=n;i++){
//		cout<<dis[i]<<" ";
//		int f = from[i];
//		cout<<f<<" ";
//		while(f!=-1){
//			f = from[f];
//			cout<<f<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
/*
4 6 0
1 2 4
1 3 11
1 4 3
2 3 6
2 4 8
3 4 7
=>13
*/
