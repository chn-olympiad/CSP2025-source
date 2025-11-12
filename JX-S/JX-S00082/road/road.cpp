#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,m,k,u,v,w,tot,ver[N*2],nxt[N*2],edg[N*2],head[N*2],ans;
queue<int>q;
void add(int u,int v,int w){
	ver[++tot]=v;
	edg[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}
void spfa(){
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=head[i],z=edg[i];
			ans+=min(ans,ans-edg[y]+z);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	//for(int )
	q.push(1);
	spfa();
	cout<<ans;
	return 0;
}
