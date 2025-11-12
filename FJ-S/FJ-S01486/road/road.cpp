#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll u,v,w;
}side[1000005];
ll n,m,k,c[15],a[15][10005],f[10005],ans;
ll cx(ll x){
	if(f[x]==x) return x;
	else return f[x]=cx(f[x]);
}
void hb(ll x,ll y){
	f[cx(x)]=f[cx(y)];
	return;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&side[i].u,&side[i].v,&side[i].w);
	}
	for(int i=1;i<=n;i++){
			f[i]=i;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=k;i++){
		if(c[i]==0)
		for(int j=1;j<=n;j++){
			for(int q=j+1;q<=n;q++){
				m++;
				side[m].u=j,side[m].v=q,side[m].w=a[i][q]+a[i][j];
			}
		}
	}
	sort(side+1,side+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(cx(side[i].u)!=cx(side[i].v)){
			hb(side[i].u,side[i].v);
			ans+=side[i].w;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
// 2025-11-01/18:17 QAQ
//²ÝÉñµÄÐÅÍ½+1 
