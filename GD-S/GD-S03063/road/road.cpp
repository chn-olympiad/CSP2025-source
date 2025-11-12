#include<bits/stdc++.h>

using namespace std;

const int N=1e4+30,M=4e6+30,INF=0x3f3f3f3f; 

#define int long long
#define PII pair<int,int> 

int n,m,k,ans=INF;
int c[10][N];

struct Node{
	int idx=0;
	int h[N],to[M],ne[M],w[M],f[N];
	void add(int u,int v,int z){
		to[++idx]=v;
		w[idx]=z;
		ne[idx]=h[u];
		h[u]=idx;
	}
}x;

int kl(Node x){
	int sum=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	for(int i=x.h[1];i!=-1;i=x.ne[i]){
		int v=x.to[i];q.push({x.w[i],v});
	}
	while(!q.empty()){
		int u=q.top().second,z=q.top().first;q.pop();
		if(x.f[u]==x.f[1])continue;
		x.f[u]=x.f[1];
		sum+=z;
		for(int i=x.h[u];i!=-1;i=x.ne[i]){
			int v=x.to[i];
			if(x.f[v]!=x.f[1])q.push({x.w[i],v});
		}
	}
	return sum;
}

void work(int p){
	Node y=x;
	int n1=n,sum=0;
	for(int i=1;i<=k;i++){
		if((p>>(i-1))&1){
			sum+=c[i][0];
			n1++;y.h[n1]=-1;
			for(int j=1;j<=n;j++)y.add(n1,j,c[i][j]),y.add(j,n1,c[i][j]);
		}
	}
	ans=min(ans,sum+kl(y));
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)x.f[i]=i,x.h[i]=-1;
	for(int i=1;i<=m;i++){
		int u,v,z;cin>>u>>v>>z;
		x.add(u,v,z);x.add(v,u,z);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int j=0;j<=(1<<k)-1;j++)work(j);
	cout<<ans<<'\n';
	return 0; 
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
