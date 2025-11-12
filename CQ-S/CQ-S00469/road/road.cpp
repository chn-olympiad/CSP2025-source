#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,cnt,f[10009];
struct w{
	long long u,v,w;
}e[1000009];
bool cmp(w x,w y){
	return x.w<y.w;
}
long long gf(long long x){
	if(f[x]==x)return x;
	return f[x]=gf(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	cnt=m;
	for(int i=1;i<=n;i++)f[i]=i; 
	sort(e+1,e+1+cnt,cmp);
	long long cnt1=0;
	for(int i=1;i<=cnt;i++){
		long long fx=gf(e[i].u),fy=gf(e[i].v);
		if(fx!=fy){
			f[fx]=e[i].v;
			ans+=e[i].w;
			cnt1++;
		}
		if(cnt1==n-1)break;
	}
	printf("%lld",ans);
	return 0;
} 
