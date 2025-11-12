#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e6+6,N=2e4+4,K=34;
int n,m,k;
int u[M],v[M],w[M],c[K],a[K][N],fa[N+K],siz[N+K];
bool vis[K];
ll ans=1e17;
struct edge{
	int x,y,z;
};
vector<edge> e;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
ll calc(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i,siz[i]=1;
	}
	sort(e.begin(),e.end(),[&](edge x,edge y){
		return x.z<y.z;
	});
	ll tmp=0;
	for(auto nw:e){
		int x=nw.x,y=nw.y,z=nw.z;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		if(siz[fx]>siz[fy]) swap(fx,fy);
		fa[fx]=fy;
		siz[fy]+=siz[fx];
		tmp+=z;
	}
	return tmp;
}
void sub(){
	for(int i=1;i<=m;i++){
		e.push_back(edge{u[i],v[i],w[i]});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(!a[i][j]){
				for(int l=1;l<=n;l++){
					if(l==j) continue;
					e.push_back(edge{j,l,a[i][l]});
				}
				break;
			}
		}
	}
	cout<<calc()<<'\n';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	bool f=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int minn=1e9;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			minn=min(minn,a[i][j]);
		}
		if(minn!=0) f=1;
	}
	if(!f){
		sub();
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		e.clear();
		for(int j=1;j<=m;j++){
			e.push_back(edge{u[j],v[j],w[j]});
		}
		ll sum=0;
		for(int j=1;j<=k;j++){
			if((i>>j-1)&1){
				// vis[j]=1;
				sum+=c[j];
				for(int l=1;l<=n;l++){
					e.push_back(edge{j+n,l,a[j][l]});
				}
			}
		}
		ans=min(ans,sum+calc());
	}
	cout<<ans<<'\n';
	return 0;
}