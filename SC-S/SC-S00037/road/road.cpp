#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

using ll=long long;
const int N=1e4+15,M=2e6+1e5+5;
int n,m,k;
int head[N],tot;
struct node{
	ll to,nex,w,u;
	friend bool operator <(node a,node b){
		return a.w<b.w;
	}
};
node ptr[M];
ll w[M];
ll cost[N];
int father[N];
void build(){
	for(int i=1;i<=n;i++)
		father[i]=i;
}
int find(int x){
	if(father[x]!=x)
		return father[x]=find(father[x]);
	return x;
}
void kruskal(){
	sort(ptr+1,ptr+1+tot);
	ll ans=0,cnt=0;
	for(int i=1;i<=tot;i++){
		int fx=find(ptr[i].u);
		int fy=find(ptr[i].to);
		if(fx==fy)
			continue;
		father[fy]=fx;
		ans+=ptr[i].w;
		++cnt;
		if(cnt==n-1)
			break;
	}
	cout<<ans<<'\n';
}
void addedge(int u,int v,int c){
	ptr[++tot].to=v;
	ptr[tot].nex=head[u];
	ptr[tot].w=c;
	head[u]=tot;
	ptr[tot].u=u;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m>>k;
	build();
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		addedge(u,v,c);
		addedge(v,u,c);
	}
//	for(int i=1;i<=k;i++){
//		cin>>cost[n+i];
//		for(int j=1;j<=n;j++){
//			int c;
//			cin>>c;
//			
//		}
//	}
	kruskal();
	return 0;
}