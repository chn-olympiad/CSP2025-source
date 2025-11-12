#include <bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000006];
int a[15][100005];
vector<int> e[100005];
int b[100005];
struct I{
	int a,b;
};
vector<I> e2[100030];
int n,m,k;
int c[100005];
int d[100005];
inline bool bfs(int u,int v){
	queue<int> q;
	q.push(u);
	for(int i=1;i<=n;i++){
		b[i]=0;
	}
	b[u]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(x==v) return true;
		for(auto y:e[x]){
			if(!b[y]){
				b[y]=1;
				q.push(y);
			}
		}
	}
	return false;
}
inline int bfs2(int u,int v){
	queue<int> q;
	q.push(u);
	for(int i=1;i<=n;i++){
		b[i]=0;
	}
	c[u]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto y:e2[x]){
			if(y.a==u) continue;
			if(!b[y.a] or b[x]+y.b<b[y.a]){
				b[y.a]=b[x]+y.b;
				c[y.a]=x;
				q.push(y.a);
			}
		}
	}
	return b[v];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		e2[u[i]].push_back({v[i],w[i]});
		e2[v[i]].push_back({u[i],w[i]});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e2[100000+i].push_back({j,a[i][j]});
			e2[j].push_back({100000+i,a[i][j]});
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(!bfs(i,j)){
				ans+=bfs2(i,j);
				int k3=j;
				c[i]=0;
				for(int t=1;t<=n;t++){
					d[t]=0;
				}
				int l=1;
				d[1]=k3;
				while(k3!=0){
					d[++l]=c[k3];
					int t=c[k3];
					k3=t;
				}
				for(int k1=1;k1<l;k1++){
					for(int k2=k1+1;k2<=l;k2++){
						e[d[k1]].push_back(d[k2]);
						e[d[k2]].push_back(d[k1]);
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}