#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MaxN=1e4+100,MaxM=1e6+1000; 

int n,m,k;
ll ans=1e18;
ll a[15][MaxN],c[15];
struct EDGE{
	int u,v;
	ll w;
	EDGE(int u,int v,ll w):u(u),v(v),w(w){}
};
vector<EDGE> edge;

struct BCJ{
	int fa[MaxN],siz[MaxN];
	
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			siz[i]=1;
		}
	}
	int find(int x){
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return ;
		if(siz[x]>siz[y])swap(x,y);
		fa[x]=y;
		siz[y]+=siz[x];
	}
}b;

bool cmp(EDGE x,EDGE y){
	return x.w<y.w;
}

void dfs(int x,vector<EDGE> de,ll sum){
	if(x==k+1){
		sort(de.begin(),de.end(),cmp);
		b.init();
		for(auto i:de){
			if(b.find(i.u)!=b.find(i.v)){
				b.merge(i.u,i.v);
				sum+=i.w;
			}
		}
		ans=min(ans,sum);
		return ;
	}
	dfs(x+1,de,sum);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			de.push_back(EDGE(i,j,a[x][i]+a[x][j]));
		}
	}
	dfs(x+1,de,sum+c[x]);
}

bool check(){
	for(int i=1;i<=k;i++){
		if(c[i])return false;
		for(int j=1;j<=n;j++){
			if(a[i][j])return false;
		}
	}
	return true;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		edge.push_back(EDGE(u,v,w));
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
	
	if(check()){
		cout<<0;
		return 0;
	}
	
	dfs(1,edge,0);
	
	printf("%lld",ans);
	
	return 0;
} 
