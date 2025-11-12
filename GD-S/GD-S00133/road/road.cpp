#include <iostream>
#include <algorithm>

using namespace std;

const int N=1e4+5,M=1e6+5,K=10;

int n,m,k,c[K],fa[N+K],sz[N+K];
struct E{
	int u,v,w;
}e[M],a[K][N],usd[1<<K][N+K];
int cnt[1<<K];

int find(int x){
	while (x^fa[x])
		x=fa[x]=fa[fa[x]];
	return x;
}

bool merge(int x,int y){
	x=find(x),y=find(y);
	if (x==y) return 0;
	if (sz[x]<sz[y]) swap(x,y);
	fa[y]=x,sz[x]+=sz[y];
	return 1; 
}

void init(){
	for (int i=1;i<=n+k;i++)
		fa[i]=i,sz[i]=1;
}

int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,[](E x,E y){return x.w<y.w;});
	init();
	long long ans=0;
	for (int i=1;i<=m;i++)
		if (merge(e[i].u,e[i].v))
			usd[0][++cnt[0]]=e[i],ans+=e[i].w;
	for (int i=0;i<k;i++){
		cin>>c[i];
		for (int j=1,v;j<=n;j++)
			cin>>v,a[i][j]={n+1+i,j,v};
		sort(a[i]+1,a[i]+n+1,[](E x,E y){return x.w<y.w;});
	}
	for (int s=1;s<1<<k;s++){
		int p=0,t,j=1;
		while (!(s>>p&1)) p++;
		t=s^1<<p,init();
		for (int i=1;i<=cnt[t];i++){
			while (j<=n&&a[p][j].w<usd[t][i].w){
				if (merge(a[p][j].u,a[p][j].v))
					usd[s][++cnt[s]]=a[p][j];
				j++;
			}
			if (merge(usd[t][i].u,usd[t][i].v))
				usd[s][++cnt[s]]=usd[t][i];
		}
		while (j<=n){
			if (merge(a[p][j].u,a[p][j].v))
				usd[s][++cnt[s]]=a[p][j];
			j++;
		}
		long long sum=0;
		for (int i=0;i<k;i++)
			if (s>>i&1) sum+=c[i];
		for (int i=1;i<=cnt[s];i++)
			sum+=usd[s][i].w;
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}

