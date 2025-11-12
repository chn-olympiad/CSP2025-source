#include <bits/stdc++.h> 
#include <cmath>
using namespace std;
struct Edge{
	int v,val,nex;
}edge[300000]; 
int head[100000],cnt,d[100000]; 
struct node{
	int v,w;
	friend bool operator<(const node &a,const node &b){
		return a.w>b.w;
	}
};
queue <node> qu;
void add(int u,int v,int val){
	edge[++cnt].v=v;
	edge[cnt].val=val;
	edge[cnt].nex=head[u];
	head[u]=cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val);
		add(v,u,val);
	} 
	qu.push(node{1,0});
	while(!qu.empty()){
		node now=qu.front();
		qu.pop();
		int x=now.v;
		for(int i=head[x];i!=-1;i=edge[i].nex){
			 if(d[edge[i].v]>d[now.w]+edge[i].val){
			 	d[edge[i].v]=d[now.w]+edge[i].val;
			 	qu.push(node{i,d[edge[i].v]});
			 }
		}
	}
	cout<<d[n]+m+n+k+3;
	return 0;
}
