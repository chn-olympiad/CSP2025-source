#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
//	bool operator < (Edge b){
//		return w<b.w;
//	}
}a[20000027];
int b[10007],n,m,u,v,w,k,c;
long long ans=0;
int check(int x){
	if(b[x]==b[b[x]])return b[x];
	return b[x]=check(b[x]);
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		b[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		q.push({a[i].w,i});
	}
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n;i++){
			m++;
			a[m].u=n+i;
			if(i==1) a[m].v=n+i;
			else a[m].v=i-1;
			cin>>a[m].w;
			q.push({a[m].w,m});
		}
	}
	while(!q.empty()){
		Edge e=a[q.top().second];
		q.pop();
		b[e.v]=check(b[e.v]);
		b[e.u]=check(b[e.u]);
		if(b[e.v]==b[e.u]) continue;
		cout<<e.v<<"-"<<e.u<<":"<<e.w<<endl;
		b[b[e.v]]=b[e.u];
		ans+=e.w;
	}
	cout<<ans;
	return 0;
}
