#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10014;
const int M=1100004;
const int K=14;
const ll inf=1e18;
ll n,m,k,cnt,ans,c[K],fa[N],a[K][N];
struct node{
	ll u,v,w;
}x[M],y[M],z[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
ll Find(ll x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=Find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i].u>>x[i].v>>x[i].w;
	}
	sort(x+1,x+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	cnt=0;
	for(int i=1;i<=m;i++){
		ll u=Find(x[i].u),v=Find(x[i].v);
		if(u!=v){
			fa[u]=v;
			z[++cnt]=x[i];
			ans+=x[i].w;
			if(cnt==n-1){
				break;
			}
		}
	}
	m=cnt;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int s=0;s<(1<<k);s++){
		ll now=0,tn=n,tm=m;
		for(int i=1;i<=m;i++){
			y[i]=z[i];
		}
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				now+=c[i];
				tn++;
				for(int j=1;j<=n;j++){
					y[++tm]=(node){tn,j,a[i][j]};
				}
			}
		}
		for(int i=1;i<=tn;i++){
			fa[i]=i;
		}
		sort(y+1,y+tm+1,cmp);
		cnt=0;
		for(int i=1;i<=tm;i++){
			ll u=Find(y[i].u),v=Find(y[i].v);
			if(u!=v){
				fa[u]=v;
				now+=y[i].w;
				if(cnt==tn-1){
					break;
				}
			}
		}
		ans=min(ans,now);
	}
	cout<<ans;
	return 0;
}
