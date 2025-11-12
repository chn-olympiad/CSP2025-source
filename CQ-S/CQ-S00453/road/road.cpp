#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+20;
int n,m,k;
long long c[20],a[20][MAX];
long long f[MAX],sum;
struct edge{
	long long u,v,w;
	friend operator <(edge a,edge b){
		return a.w>b.w;
	}
};
priority_queue<edge> q;
long long find(long long x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		long long u=0,v=0,w=0;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	while(!q.empty()){
		long long u=q.top().u,v=q.top().v,w=q.top().w;
		q.pop();
		long long a=find(u),b=find(v);
		if(a!=b){
			f[a]=b;
			sum+=w;
		}
	}
	cout<<sum;
	return 0;
}

