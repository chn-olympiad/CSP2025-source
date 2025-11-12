#include <bits/stdc++.h>
#define int long long
#define debug(x) cout<<#x<<" = "<<x<<' '
#define N 10050
#define K 1050
#define M 2000010
using namespace std;

struct Edge{
	int l,r,w,next;
}e[2*M];
int elast[N];

struct edge{
	int l,r,w;
}kr[M];
bool cmp(edge a,edge b){
	return a.w < b.w;
}

struct dot{
	int num,id;
};
bool operator <(dot a,dot b){
	return a.num > b.num;
}
priority_queue<dot> pq;

int n,m,k,len=1,ttp,ans;
int fa[N],c[20];
int dis[K][K],ds[20][20];
bool vis[N];

int Find(int x){
	if(fa[x] == x) return x;
	return fa[x]=Find(fa[x]);
}

void add(int l,int r,int w){
	e[len].l=l,e[len].r=r,e[len].w=w;
	e[len].next=elast[l];
	elast[l]=len++;
}

void merge(int l,int r,int w){
	l=Find(l),r=Find(r);
	if(l != r) fa[l]=r,ans+=w;
}

void Merge(int l,int r,int w){
	int L=Find(l),R=Find(r);
	if(L != R){
		fa[L]=R,ttp+=w;
		add(l,r,w),add(r,l,w);
	}
}

void init(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int l,r,w;
		cin>>l>>r>>w;
		kr[i]={l,r,w};
	}
	sort(kr+1,kr+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>ds[i][j];
	}
	
	for(int i=1;i<=m;i++) Merge(kr[i].l,kr[i].r,kr[i].w); //Krusual
}

void Dijstra(int Front){
	for(int i=1;i<=n;i++) dis[Front][i]=1e18,vis[i]=0;
	dis[Front][Front]=0;
	pq.push({0,Front});
	
	while(!pq.empty()){
		int id=pq.top().id;
		pq.pop();
		
		if(vis[id]) continue;
		vis[id]=1;
		
		for(int i=elast[id];i;i=e[i].next){
			int r=e[i].r;
			if(dis[Front][r] > dis[Front][id]+e[i].w && !vis[r]){
				dis[Front][r]=dis[Front][id]+e[i].w;
				pq.push({dis[Front][r],r});
			}
		}
	}
}

int solve(){
	if(k == 0) return ttp;
	else{
		for(int i=1;i<=n;i++)
			Dijstra(i);
		int tot=m;
		for(int w=1;w<=k;w++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(dis[i][j] > ds[w][i]+ds[w][j])
						kr[++tot]={i,j,ds[w][i]+ds[w][j]};
		sort(kr+1,kr+1+tot,cmp);
//		debug(tot)<<endl;
		
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=tot;i++) merge(kr[i].l,kr[i].r,kr[i].w);
		return ans;
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int T=1;
	while(T--){
		init();
		cout<<solve()<<endl;
	}
	return 0;
}

