#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,m,k,u,v,w,fa[N],ans=1e17;
ll c[20],way[20][10010];
ll find(ll x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}/*
struct node{
	int bh,add,v;
	node(){}
	node(ll x,ll y,ll z){bh=x;add=y;v=z;}
}a[N<<2];
int CNT,h[N<<2];
void insert(int x,int y,int z){
	a[++CNT]=node(y,h[x],z);
	h[x]=CNT;
}*/
struct node{
	ll next,va;
};
vector<node>a[10010];
struct road{
	ll st,en,va;
}tr[N<<2];
bool cmp(road x,road y){
	return x.va<y.va;
}
unordered_map<ll,ll>flag[N];
ll kruskal(ll cost){
	ll res=cost,cnt=0,f=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			flag[i][j]=1e16;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		for(auto j=a[i].begin();j!=a[i].end();j++){
			if((*j).va<flag[i][(*j).next]){
				flag[i][(*j).next]=(*j).va;
				tr[++cnt].st=i;
				tr[cnt].en=(*j).next;
				tr[cnt].va=(*j).va;
			}
		}
	}
	sort(tr+1,tr+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		ll fx=find(tr[i].st),fy=find(tr[i].en);
		if(fx!=fy){
			fa[fx]=fy;
			res+=tr[i].va;
			f++;
		}
		if(f==n-1)
			break;
	}
	return res;
}
void work(ll x,ll cost){
	if(x>k){
		ans=min(ans,kruskal(cost));
		return;
	}
	work(x+1,cost);
	for(int i=1;i<=n;i++){
		if(x!=i){
			a[x].push_back({i,way[x][i]});
		}
	}
	work(x+1,cost+c[x]);
	for(int i=1;i<=n;i++){
		if(x!=i){
			a[x].pop_back();
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back({v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>way[i][j];
		c[i]+=way[i][i];
	}
	work(1,0);
	cout<<ans;
	return 0;
}
