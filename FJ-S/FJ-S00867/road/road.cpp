#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,fa[N],b[11],c[11][N];
long long ans;
bool vis[N],vis2[11];
struct Node{
	int v,w;
};
struct Edge{
	int u,v,w;
}e[M];
vector<Node> a[N];
int find(int x){
	if(fa[x]!=x){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1,u,v,w;i<=m;i++){
			cin>>u>>v>>w;
			e[i]=(Edge){u,v,w};
		}
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1,cnt=0,u,v,r1,r2;i<=m;i++){
			if(cnt==n-1) break;
			u=e[i].u,v=e[i].v;
			r1=find(u),r2=find(v);
			if(r1!=r2){
				fa[r2]=r1;
				cnt++;
				ans+=e[i].w*1LL;
			}
		}
		cout<<ans<<endl;
	}
	else{
		for(int i=1,u,v,w;i<=m;i++){
			cin>>u>>v>>w;
			a[u].push_back((Node){v,w});
			a[v].push_back((Node){u,w});
		}
		for(int i=1;i<=k;i++){
			cin>>b[i];
			for(int j=1;j<=n;j++){
				cin>>c[i][j];
			}
		}
		queue<int> q;
		vis[1]=1;
		q.push(1);
		while(!q.empty()){
			int u=q.front();q.pop();
			int mw=INT_MAX,mv=-1;
			bool flag=0;
			for(Node e:a[u]){
				if(!vis[e.v]){
					if(e.w<mw){
						mw=e.w;
						mv=e.v;
					}
				}
			}
			for(int i=1,w;i<=k;i++){
				if(!vis2[i]){
					w=1+c[i][u];
				}else{
					w=c[i][u];
				}
				for(int v=1;v<=n;v++){
					if(vis[v]) continue;
					if(w+c[i][v]<mw){
						mw=w+c[i][v];
						mv=v;
						flag=i;
					}
				}
			}
			if(mv==-1) continue;
			vis2[flag]=1;
			vis[mv]=1;
			ans+=mw*1LL;
			q.push(mv);
			//cout<<u<<' '<<mv<<' '<<mw<<endl;
		}
		cout<<ans;
	}
	return 0;
}
