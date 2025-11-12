#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,x,y,z,kk;
ll fa[10010];
ll ans;
struct abc{
	ll w,v,u;
}a[2001000];

ll find(ll s){
	if(fa[s]!=s) fa[s]=find(fa[s]);
	return fa[s];
}

void unionn(ll xl,ll x2){
	ll rl=find(xl);
	ll r2=find(x2);
	fa[r2]=rl; 
}

bool cmp(abc lss,abc wzc){
	return lss.w<wzc.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==0){
		for(ll i=1;i<=n;i++) fa[i]=i;
		for(ll i=1;i<=m;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			a[i].u=x;
			a[i].v=y;
			a[i].w=z;
		}
		sort(a+1,a+1+m,cmp);
		for(ll i=1;i<=m;i++){
			if(kk==n-1) break;
			if(find(a[i].u)!=find(a[i].v)){
				unionn(a[i].u,a[i].v);
				kk++;
				ans+=a[i].w;
			}
		}
		printf("%lld\n",ans);
	}
	else printf("0\n");
	return 0;
}
