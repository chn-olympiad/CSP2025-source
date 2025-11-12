#include<bits/stdc++.h>
using namespace std;
#define MAXN 10055
int n,m,k;
struct edge{
	int u,v,w;
	inline bool operator<(const edge&t)const{
		return w<t.w;
	}
};
vector<edge>e,e2;
int fa[MAXN];
int find(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x>y)fa[x]=y;
	else fa[y]=x;
}
int c[15],a[15][MAXN];
int mn2[(1<<10)+5]; 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i)fa[i]=i;
	e.reserve(n-1);
	e2.reserve((k+1)*n-1);
	{
		vector<edge>es;
		es.reserve(m);
		for(int i=1,u,v,w;i<=m;++i){
			cin>>u>>v>>w;
			es.emplace_back(edge{u,v,w});
		}
		sort(es.begin(),es.end());
		for(auto&it:es){
			if(find(it.u)!=find(it.v)){
				e.emplace_back(it);
				merge(it.u,it.v);
			}
		}
	}
	for(int i=0;i<k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}
	long long ans=LLONG_MAX;
	for(int s=0;s<(1<<k);++s){
		long long sum=0;
		e2.assign(e.begin(),e.end());
		int mn=e.back().w;
		for(int s2=0;s2<s;++s2)if((s&s2)==s2)mn=min(mn,mn2[s2]);
		for(int i=0;i<k;++i)if(s&(1<<i)){
			sum+=c[i];
			for(int j=1;j<=n;++j)if(a[i][j]<=mn){
				e2.emplace_back(edge{j,n+1+i,a[i][j]});
			}
		}
		sort(e2.begin(),e2.end());
		for(int i=1;i<=n+k;++i)fa[i]=i;
		for(auto&it:e2){
			if(find(it.u)!=find(it.v)){
				sum+=it.w;
				merge(it.u,it.v);
				mn=it.w;
			}
		}
		mn2[s]=mn;
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
} 
