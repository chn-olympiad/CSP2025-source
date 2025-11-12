#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,inf=1e9;
int n,m,k,head[N],ne[N],hu[N],to[N],ans;
int idx,cnt,d[N],vis[N],aaa[N];
void add(int u,int v,int w){
	ne[++idx]=head[u];
	head[u]=idx;
	hu[idx]=w;
	to[idx]=v;
}
void p(int u){
	queue<int> q;
	for(int i=1;i<=2*n;i++){
		d[i]=inf;
	}
	d[u]=0;
	for(int i=head[u];i;i=ne[i]){
		q.push(to[i]);
		d[to[i]]=hu[i];
		aaa[to[i]]=hu[i];
	}
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int i=head[v];i;i=ne[i]){
			if(d[to[i]]>d[v]+d[hu[i]]){
				vis[to[i]]=true;
				d[to[i]]=d[v]+hu[i];
				aaa[to[i]]=hu[i];
				hu[i]=0;
				q.push(to[i]);
			}
		}
	} 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	p(1);
	for(int i=1;i<=n;i++)ans+=aaa[i];
	cout<<ans;
	return 0;
}

