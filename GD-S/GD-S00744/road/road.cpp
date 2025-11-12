#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,u[1000005],v[1000005],w[1000005],f[10015],ans=1e18,a[11][10005],c[11],nu,ja,nh;
bool b[11];
struct o{
	ll u,v,w;
};
bool operator<(o x,o y){
	return x.w>y.w;
}
priority_queue<o>q,z;
ll find(ll x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",u+i,v+i,w+i);
		q.push({u[i],v[i],w[i]});
		z.push({u[i],v[i],w[i]});
	}for(ll i=1;i<=n+k;i++)f[i]=i;
	for(ll i=1;i<=k;i++){
		scanf("%lld",c+i);
		for(ll j=1;j<=n;j++)scanf("%lld",a[i]+j);
	}for(ll i=0;i<(1<<k);i++){
		nh=n;
		ja=nu=0;
		q=z;
		for(ll j=0;j<k;j++){
			if(!(i&(1<<j)))continue;
			ja+=c[j+1];
			for(ll l=1;l<=n;l++)q.push({n+j+1,l,a[j+1][l]});
			nh++;
		}for(ll j=1;j<=n+k;j++)f[j]=j;
		while(nu<nh-1&&!q.empty()){
			o t=q.top();
			q.pop();
			if(find(t.u)==find(t.v))continue;
			f[find(t.u)]=find(t.v);
			nu++;
			ja+=t.w;
		}if(ja<ans)ans=ja;
	}printf("%lld",ans);
	return 0;
}
