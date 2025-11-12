#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e4+15,M=1e6+5,inf=1e15+5;
struct edge{
	int u,v;
	int w;
}a[M],b[N*10];
int n,m,k;
LL ans=inf;
int fa[N],sz[N];
vector<edge> vec;
int c[15];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int u){
	if(fa[u]==u) return u;
	return fa[u]=find(fa[u]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int num=(i-1)*n+j;
			cin>>b[num].w;
			b[num].v=j;
			b[num].u=n+i;
		}
	}
	for(int S=0;S<(1<<k);S++){
		vec.clear();
		LL sum=0;
		for(LL i=1;i<=k;i++){
			if(S&(1<<(i-1))){
				sum+=c[i];
				for(int j=1;j<=n;j++){
					vec.push_back(b[(i-1)*n+j]);
				}
			}
		}
		sort(vec.begin(),vec.end(),cmp);
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
			sz[i]=1;
		}
		int p=0;
		bool f=1;
		for(int i=1;i<=m;i++){
			int x,y;
			while(p<vec.size()&&(vec[p].w<=a[i].w)){
				x=find(vec[p].u);y=find(vec[p].v);
				if(x!=y){
					if(sz[x]<sz[y]) swap(x,y);
					fa[y]=x;
					sz[x]+=sz[y];
					sum+=vec[p].w;
				}
				p++;
			}
			x=find(a[i].u);y=find(a[i].v);
			if(x!=y){
				if(sz[x]<sz[y]) swap(x,y);
				fa[y]=x;
				sz[x]+=sz[y];
				sum+=a[i].w;
			}
			if(sum>=ans){
				f=0;
				break;
			}
		}
		if(f){
			ans=sum;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
