#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int end,weight,nxt;
}edge[1000005];
int c[1000005],head[1000005];
int len[1000005],vis[1000005],prenode[1000005],preedge[1000005],viss[2000005];
int n,m,k,ans;
void add_edge(int u,int v,int w,int i){
	edge[i].end=v;
	edge[i].weight=w;
	edge[i].nxt=head[u];
	head[u]=i;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		len[i]=INT_MAX,head[i]=-1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w,i);
		add_edge(v,u,w,i+m);
	}
	
	//cout<<1<<endl;
	len[1]=0,prenode[1]=1,vis[1]=1;
	int now_edge=head[1],now_node=1;
	for(int i=1;i<=n;i++){
		int o=now_edge;
		while(now_edge!=-1){
			//cout<<now_edge<<" ";
			if(vis[edge[now_edge].end]){
				now_edge=edge[now_edge].nxt;
				continue;
			}
			if(edge[now_edge].weight<edge[o].weight)o=now_edge;
			if(edge[now_edge].weight+len[now_node]<len[edge[now_edge].end]){
				len[edge[now_edge].end]=min(len[edge[now_edge].end],edge[now_edge].weight+len[now_node]);
				preedge[edge[now_edge].end]=now_edge;
				prenode[edge[now_edge].end]=now_node;
			}
			now_edge=edge[now_edge].nxt;
		}
		now_edge=head[edge[o].end];
		now_node=edge[o].end;
		vis[edge[o].end]=1;
	}
	/*
	for(int i=1;i<=m*2;i++){
		cout<<edge[i].end<<" "<<edge[i].weight<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<preedge[i]<<" ";
	cout<<endl;*/
	for(int i=2;i<=n;i++){
		int o=i;
		while(prenode[o]!=o){
			//cout<<preedge[o]<<" ";
			ans+=edge[preedge[o]].weight*(!viss[preedge[o]]);
			viss[preedge[o]]=1;
			o=prenode[o];
		}
	}
	cout<<ans<<endl;
	return 0;
}
