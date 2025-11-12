#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,k,c[15],f[10005];
ll a[15][10005];
struct tt{
	int v;
	ll w;
};
vector<tt> e[10005];
struct ttt{
	int u,v;
	ll w;
	friend bool operator < (ttt p,ttt q){
		return p.w<q.w;
	}
}l[2000005];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		l[i]={u,v,w};
	}
	bool bl=true;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) bl=false;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(bl){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll mn=1e10;
				for(int l=1;l<=k;l++){
					mn=min(mn,a[l][i]+a[l][j]);
				}
				l[++m]={i,j,mn};
			}
		}
	}
	sort(l+1,l+1+m);
	for(int i=1;i<=n;i++) f[i]=i;
	ll ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int fu=find(l[i].u),fv=find(l[i].v);
		if(fu!=fv){
			f[fu]=fv;
			cnt++;
			ans+=l[i].w;
			if(cnt==n-1) break;
		}
	}
	printf("%lld",ans);
	return 0;
}
