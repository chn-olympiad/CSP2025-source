#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
struct node{
	int u,v,w;
}e[2100005];
int fa[10005],n,m,k,tot,c[11],mn[11],mnid[11],pos[11],rans=200000000000000001;
struct node2{
	int v,id;
}a[11][10001];
vector<node2> g[10005]; 
bool vis[11];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
	return;
}
void insert(int u,int v,int w){
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	int id=tot;
	while(id>1){
		if(e[id].w<e[id/2].w){
			swap(e[id],e[id/2]);
			id/=2;
		}
		else break;
	}
	return;
}
void pop(){
	swap(e[1],e[tot]);
	tot--;
	int id=1;
	while(id*2<=tot){
		if(id*2==tot){
			if(e[id].w>e[id*2].w){
				swap(e[id],e[id*2]);
			}
			return;
		}
		if(e[id*2].w<e[id*2+1].w){
			if(e[id].w>e[id*2].w){
				swap(e[id],e[id*2]);
				id*=2;
			}
			else break;
		}
		else{
			if(e[id].w>e[id*2+1].w){
				swap(e[id],e[id*2+1]);
				id=id*2+1;
			}
			else break;
		}
	}
	return;
}
bool cmp(node2 hwh,node2 qwq){
	return hwh.v<qwq.v;
}
void work(){
	tot=0;
	for(int i=1;i<=k;i++){
		mn[i]=20000000001;
		pos[i]=1;
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<g[1].size();i++){
		insert(1,g[1][i].id,g[1][i].v);
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		//cout<<i<<endl;
		//cout<<tot<<endl;
		while(find(e[1].u)==find(1)&&find(e[1].v)==find(1)&&tot!=0) pop();
		int id,val=20000000001;
		for(int j=1;j<=k;j++){
			while(find(a[j][pos[j]].id)==find(1)){
				int num=a[j][pos[j]].v;
				if(vis[j]==0) num+=c[j];
				if(num<mn[j]){
					mn[j]=num;
					mnid[j]=a[j][pos[j]].id;
				}
				pos[j]++;
			}
			int num=mn[j]+a[j][pos[j]].v;
			if(vis[id]==1) num-=mn[j];
			if(num<val){
				val=num;
				id=j;
			}
		}
		if(e[1].w<val){
			//cout<<e[1].u<<" "<<e[1].v<<endl;
			if(find(e[1].u)!=find(1)){
				for(int j=0;j<g[e[1].u].size();j++){
					insert(e[1].u,g[e[1].u][j].id,g[e[1].u][j].v);
				}
			}
			else{
				for(int j=0;j<g[e[1].v].size();j++){
					insert(e[1].v,g[e[1].v][j].id,g[e[1].v][j].v);
				}
			}
			merge(e[1].u,e[1].v);
			ans+=e[1].w;
		}
		else{
			int u=mnid[id],v=a[id][pos[id]].id;
			if(find(u)!=find(1)){
				for(int j=0;j<g[u].size();j++){
					insert(u,g[u][j].id,g[u][j].v);
				}
			}
			else{
				for(int j=0;j<g[v].size();j++){
					insert(v,g[v][j].id,g[v][j].v);
				}
			}
			merge(mnid[id],a[id][pos[id]].id);
			vis[id]=1;
			ans+=val;
		}
		//cout<<val<<" "<<e[1].w<<endl;
		/*
		for(int j=1;j<=tot;j++){
			cout<<e[j].u<<" "<<e[j].v<<" "<<e[j].w<<endl;
		}
		*/
		/*
		for(int j=1;j<=n;j++){
			cout<<fa[j]<<" ";
		}
		*/
		//cout<<endl;
		/*
		for(int j=1;j<=k;j++){
			cout<<mn[j]<<" "<<pos[j]<<endl;
		}
		*/
	}
	//cout<<"!!"<<endl;
	rans=min(rans,ans);
}
signed main(){
	//freopen("road2.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back((node2){w,v});
		g[v].push_back((node2){w,u});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j].v;
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	work();
	cout<<rans;
	return 0;
}
