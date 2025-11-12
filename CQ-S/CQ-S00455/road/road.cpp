#include<bits/stdc++.h>
#define ll long long
#define N 10005
#define M 1000005
using namespace std;
inline char nc(){
	static char buf[1000000],*p(buf),*q(buf);
	return (q==p&&(q=(p=buf)+fread(buf,1,1000000,stdin),q==p)?EOF:*p++); 
}
inline ll read(){
	char c = nc();
	ll res = 0;
	while(c<'0'||c>'9') c=nc();
	while(c>='0'&&c<='9') res=res*10+c-'0',c=nc();
	return res;
}
struct node{ll x,y,z;}p[M],que[N];
inline bool cmp(node a,node b){return a.z<b.z;}
ll n,m,k,i,j,l,c[11],fath[N],tot,ans,vs[11],ps[11];
pair<ll,ll> v[11][N];
inline ll gf(ll x){return x==fath[x]?x:fath[x]=gf(fath[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read(); 
	for(i=1;i<=m;i++) p[i].x=read(),p[i].y=read(),p[i].z=read();
	sort(p+1,p+m+1,cmp);
	for(i=1;i<=n;i++) fath[i]=i;
	for(i=1;i<=m;i++) if(gf(p[i].x)!=gf(p[i].y)) ans+=p[i].z,fath[gf(p[i].x)]=gf(p[i].y),que[++tot]=p[i];
	for(i=1;i<=k;i++){
		c[i]=read();
		for(j=1;j<=n;j++) v[i][j].first=read(),v[i][j].second=j;
		sort(v[i]+1,v[i]+n+1);
	}
	for(i=1;i<(1<<k);i++){
		ll num = 0,all = n;
		for(j=0;j<k;j++) if((i>>j)&1) num+=c[j+1],vs[j+1]=1,ps[j+1]=1,all++;
		for(j=1;j<=n+k;j++) fath[j]=j;
		ll pnt = 1;
		for(j=1;j<=all-1;j++){
			ll x = -1,y = -1,z = 0x3f3f3f3f3f3f3f3f;
			while(pnt<=tot&&gf(que[pnt].x)==gf(que[pnt].y)) pnt++;
			if(pnt<=tot&&que[pnt].z<z) z=que[pnt].z,x=que[pnt].x,y=que[pnt].y;
			for(l=1;l<=k;l++){
				if(!vs[l]) continue;
				while(ps[l]<=n&&gf(l+n)==gf(v[l][ps[l]].second)) ps[l]++;
				if(ps[l]<=n&&v[l][ps[l]].first<z) z=v[l][ps[l]].first,x=l+n,y=v[l][ps[l]].second;
			}
			num += z,fath[gf(x)] = gf(y);
		}
		ans = min(ans,num);
		for(j=1;j<=k;j++) vs[j]=0,ps[j]=0; 
	}
	printf("%lld\n",ans);
	return 0;
}
