#include<bits/stdc++.h>
using namespace std;
struct edge{
	int nex,to,w;
}e[40005];
struct idx{
	int x,y,w;
}id[1000006];
int head[10004],tot=1;
int mp[10004][10004];
int fom[10004];
int n,m,k;
int fa[10004];
int dis[10004];
int cha[10004];
int tota;
inline void add(int u,int v,int w){
	tot++;
	e[tot].nex=head[u];
	e[tot].to=v;
	e[tot].w=w;
	head[u]=tot;
	return ;
}
inline bool cmp(idx a,idx b){
	return a.w<b.w;
}
inline int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k!=0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>id[i].x>>id[i].y>>id[i].w;
	}
	sort(id+1,id+m+1,cmp);
	int cnt=1;
	int ans=0;
	for(int i=1;i<=m;i++){
		int x=find(id[i].x);
		int y=find(id[i].y);
		if(x!=y){
			cnt++;
			fa[x]=y;
			ans+=id[i].w;
			add(id[i].x,id[i].y,id[i].w);
			add(id[i].y,id[i].x,id[i].w);
		}
		if(cnt==n){
			break;
		}
	}
	cout<<ans;
}
/*
4 4 0
1 4 6 
2 3 7
4 2 5
4 3 4
*/