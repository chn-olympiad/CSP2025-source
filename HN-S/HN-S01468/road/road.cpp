#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e4+10,M=1e6+10;
struct code{
	int u,v,w;
}b[M];
struct node{
	int to,next,len;
}a[M*2];
int n,m,K,k,p[M],c[15][N],d[N],ans;
void add(int u,int v){
	a[++k].to=v;
	a[k].next=p[u];
	p[u]=k;
}
void dij(){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=n;i++){
		q.push({d[i],i});
	}
	while(!q.empty()){
		int dis=q.top().first,u=q.top().second;
		q.pop();
		for(int i=p[u];i;i=a[i].next){
			int t=a[i].to;
			if(d[u]+a[i].len<d[t]){
				d[t]=d[u]+a[i].len;
				q.push({d[t],t});
				ans=min(ans,d[t]);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
		d[i]=b[i].w;
		add(b[i].u,b[i].v),add(b[i].v,b[i].u);
	}
	for(int i=1;i<=K;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];
		}
	}
	dij();
	cout<<ans;
	return 0;
}
