#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,f[100010],ans,vis[100010],zfy[20],l,minn=1e18,fl[100010];
struct node{
	int u,v,w;
	bool operator<(const node &a){
		return w<a.w;
	}
}e[2000010];
struct point{
	int d,pos;
	bool operator<(const point &w){
		return d<w.d;
	}
}zy[100010];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
set<int>t;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=0;i<k;i++){
		int w;
		cin>>zfy[i];
		for(int j=1;j<=n;j++)
			cin>>w,e[m+i*n+j]={n+i+1,j,w};
		zy[i+1]={zfy[i],i+1};
	}
	m=m+k*n;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int e1=find(e[i].u),e2=find(e[i].v);
		if(e1!=e2){
			f[e1]=e2;
			if(e[i].u>n) zy[e[i].u-n].d-=e[i].w;
			if(e[i].u<=n) t.insert(e[i].u);
			if(e[i].v<=n) t.insert(e[i].v);
			l=t.size();
			if(l==n) break;
		}
	}
	sort(zy+1,zy+k+1);
	for(int o=0;o<=k;o++){
		ans=0;
		fl[n+zy[o].pos]=1;
		for(int i=1;i<=n+k;i++) f[i]=i;
		t.clear();
		memset(vis,0,sizeof vis);
		for(int i=1;i<=m;i++){
			if(e[i].u>n&&!fl[e[i].u]) continue;
			int e1=find(e[i].u),e2=find(e[i].v);
			if(e1!=e2){
				ans+=e[i].w,f[e1]=e2;
				if(e[i].u>n&&!vis[e[i].u]) ans+=zfy[e[i].u-n-1],vis[e[i].u]=1;
				if(e[i].u<=n) t.insert(e[i].u);
				if(e[i].v<=n) t.insert(e[i].v);
				l=t.size();
				if(l==n) break;
			}
		}	
		minn=min(minn,ans);
	}
	cout<<minn;
}
/*
一眼最小生成树。
我是LateSight 我的锣鼓UID是593499
我要起飞！！！
我要上GD迷惑行为大赏！！！
*/ 
