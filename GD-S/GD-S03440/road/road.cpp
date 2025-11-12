#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e4+15,M=1e6+1e5+155,K=10;//15!
const ll INF=0x3f3f3f3f3f3f3f3f;
ll c[N];
ll a[15][N];
struct edge{
	int u,v;
	ll w;
	bool operator < (const edge& b)	const{
		return w<b.w;
	}
}el[M];
struct node{
	int id;
	ll dis;
	bool operator < (const node& b) const{
		return dis<b.dis;
	}
};
vector<edge>e[N];
bool myis_ex(int s,int id){
	return (s&(1<<(id-1)));
}
ll cs[(1<<K)+5];
int n,m,k;
int top=0;
int fa[N],siz[N];
int find(int x){
	if(fa[x]!=x)	fa[x]=find(fa[x]);
	return fa[x];
}
bool judge(int x,int y){
	return (find(x)!=find(y));
}
void merge(int x,int y){
	int u=find(x),v=find(y);
	if(u==v)	return;
	if(siz[u]<siz[v])swap(u,v);
	fa[v]=fa[u];
	siz[u]+=siz[v];
}

//int fa2[N],siz2[N];
//int find2(int x){
//	if(fa2[x]!=x)	fa2[x]=find(fa2[x]);
//	return fa2[x];
//}
//bool judge2(int x,int y){
//	return (find2(x)!=find2(y));
//}
//void merge2(int x,int y){
//	int u=find2(x),v=find2(y);
//	if(u==v)	return;
//	if(siz2[u]<siz2[v])swap(u,v);
//	fa2[v]=fa2[u];
//	siz2[u]+=siz2[v];
//}
ll ans=INF;
ll myKruskal(int s,ll fs){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		siz[i]=i;
	}
	ll sum=fs;
	for(int i=1;i<=top;i++){
		if((el[i].u>n&&!myis_ex(s,el[i].u-n))||(el[i].v>n&&!myis_ex(s,el[i].v-n)))
			continue;
		if(judge(el[i].u,el[i].v)){
			merge(el[i].u,el[i].v);
			sum+=el[i].w;
			if(sum>ans)	return INF;
		}
	}
	return sum;
}
int lowb(int x){
	return (x&(-x));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		el[++top]={u,v,w};
		e[u].push_back({u,v,w});
		e[v].push_back({v,u,w});
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		cs[(1<<(j-1))]=c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
			el[++top]={i,n+j,a[j][i]};
			e[i].push_back({i,n+j,a[j][i]});
			e[n+j].push_back({n+j,i,a[j][i]});
		}
	}
	sort(el+1,el+top+1);
	for(int s=0;s<(1<<k);s++){
		cs[s]=cs[s-lowb(s)]+cs[lowb(s)];
	}
	for(int s=(1<<k);s>=0;s--){
		if(cs[s]>=ans)	continue;
		ll temp=myKruskal(s,cs[s]);
//		cerr<<temp<<"   ";
		ans=min(ans,temp);
	}
	cout<<ans;
	
	return 0;
} 
