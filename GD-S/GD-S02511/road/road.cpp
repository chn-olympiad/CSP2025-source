#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
struct str{
	int u,v,w;
}e;
bool operator < (str a,str b){
	return a.w<b.w;
}
int n,m,k,c[maxn],a[10][100005],fa[10005],ans;
priority_queue<str>q;
inline int findfa(int x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=findfa(fa[x]);
	}
}
void kruskal(){
	while(!q.empty()){
		e=q.top();
		q.pop();
		if((e.u)!=findfa(e.v)){
			ans+=e.w;
			fa[e.u]=e.v;
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e.u>>e.v>>e.w;
		q.push(e);
		e.u^=e.v^=e.u^=e.v;
		q.push(e);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e.u=n+i,e.v=j,e.w=a[i][j];
				q.push(e);
				e.u^=e.v^=e.u^=e.v;
				q.push(e);
			}
		}
		kruskal();
		cout<<ans;
	return 0;
}
