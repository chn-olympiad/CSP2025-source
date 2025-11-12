#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20;
ll n,m,k,x,y,z,fa[N],siz[N],c[N],ans,f[N],www[N];
struct edge1{
	ll u,v,w;
	bool operator<(const edge1 &x) const{
		return w>x.w;
	}
};
ll find(ll x){
	if(x==fa[x]) return x;
	ll d=find(fa[x]);
	fa[x]=d;
	return d;
}
priority_queue<edge1> q;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		q.push({x,y,z});
	}
	if(k==0){
		while(!q.empty()){
			ll u=q.top().u,v=q.top().v,w=q.top().w;
			q.pop();
			ll fx=find(u),fy=find(v);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=w;
			}
		}
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=k;i++){
			cin>>c[n+i];
			fa[n+i]=n+i;
			for(int j=1;j<=n;j++){
				cin>>z;
				q.push({j,i+n,z+c[i+n]});
			}
		}
		while(!q.empty()){
			ll u=q.top().u,v=q.top().v,w=q.top().w;
			q.pop();
			ll fx=find(u),fy=find(v);
			if(fx!=fy){
				f[u]++;
				f[v]++;
				www[u]=www[v]=w;
				fa[fx]=fy;
				siz[fy]+=siz[fx];
				ans+=w;
			}
			if(siz[fy]>=n) break;
		}
		for(int i=n+1;i<=n+k;i++){
			if(f[i]>0){
				if(f[i]>1) ans-=(f[i]-1)*c[i];
				else ans-=www[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
