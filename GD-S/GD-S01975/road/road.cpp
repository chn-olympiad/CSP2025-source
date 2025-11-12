#include<bits/stdc++.h>
using namespace std;
const int maxn=10007;
int n,m,k,fa[maxn];
long long ans,a[11][maxn],c[11];
bool vis[11];
int find(int x){
	if(x!=fa[x]){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void unite(int x,int y){
	fa[find(x)]=find(y);
}
struct edge{
	int u,v;
	long long w;
};
struct cmp{
	bool operator()(const edge &x,const edge &y){
		return x.w>y.w;
	}
};
inline long long cst(int ind){
	return vis[ind]?0:c[ind];
}
priority_queue<edge,vector<edge>,cmp>q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=n-1;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		q.push(edge{u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		if(c[i]==0){
			for(int x=1;x<n;x++){
				for(int y=x+1;y<=n;y++){
					q.push(edge{x,y,a[i][x]+a[i][y]});
				}
			}
		} 
	}
	while(cnt){
		int u=q.top().u,v=q.top().v;
		long long w=q.top().w;
		q.pop();
		if(find(u)!=find(v)){
			unite(u,v);
			int j=0;
			for(int i=1;i<=k;i++){
				if(a[i][u]+a[i][v]+cst(i)<=w){
					w=a[i][u]+a[i][v]+cst(i);
					j=i;
				}
			}
			ans+=w;
			vis[j]=true;
			cnt--;
		}
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
