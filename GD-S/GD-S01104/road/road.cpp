#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m,k;
int a[maxn][maxn];
int c[maxn];
struct node{
	int v,w;
};
vector<node> p[maxn];
int e[maxn][maxn];
bool bd[maxn];
/*
t2我感觉这就是要求最小生成树
但是我把 kruscal和 prim都忘了
gg！ 
哦又想了一下，可以只留下两个点之间最短的边 
然后dijkstra即可 
等一下prim好像跟dijk就差了一行 
完蛋了我还是想不起来
摆
//froepen("road.in","r",stdin);
Let my heart bravely spread the wings
Let the clouds heal me of the stings

参加的第二届提高组凉了吗 ……
吃吃饭你这家伙
这么裸的题我居然忘了算法
希望j组可以有1=，填补我破碎的心
事已至此，先写dijkstra吧 
许愿s组三等 
不知道luogu会不会出迷惑行为大赏
想上
*/
bool vis[maxn];
int d[maxn];
int rp=1919810;
void dijk(){
	memset(d,0x3f,sizeof(d));
	priority_queue<pair<int,int> > q;
	d[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<p[u].size();i++){
			int vv=p[u][i].v,ww=e[u][vv];
			if(d[vv]>d[u]+ww){
				d[vv]=d[u]+ww;
				q.push({-d[vv],vv});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=d[i];
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		p[u].push_back({v,w});
		p[v].push_back({u,w});
		e[u][v]=w;
		e[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(e[i][j]>c[i]+a[i][j]) e[i][j]=c[i]+a[i][j],bd[i]=1,c[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(e[i][j]>c[i]+a[i][j]) e[i][j]=c[i]+a[i][j],bd[i]=1;
		}
	}
	dijk();
	return 0;
}
