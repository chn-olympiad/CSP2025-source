#include<bits/stdc++.h>
using namespace std;
struct node{
	int from,to,val;
	bool operator < (const node &other)const{
		return val>other.val;
	}
};
priority_queue<node>q;
int fa[11234];
long long ans=0;
int total=0;
int n,m,k;
int find(int x){
	if(fa[x]==0)fa[x]=x;
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void kruskal(){
	while(!q.empty()){
		if(total>=n-1)return;
		node temp=q.top();
		q.pop();
		if(find(temp.from)==find(temp.to))continue;
		ans+=temp.val;
		fa[find(temp.from)]=find(temp.to);
		total++;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		q.push({u,v,w});
	}
	int cnt=1;
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			if(w==0){
				q.push({cnt,j,0});
			}
		}
		cnt++;
	}
	kruskal();
	cout<<ans;
	return 0;
}
