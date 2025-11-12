#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
ll n,m,k,cnt,ans=9e16,c[N],fa[N];
struct NN{ll x,y,w,flag;}a[N];
bool cmp(NN x,NN y){return x.w<y.w;}
ll find(ll x){return x!=fa[x]?fa[x]=find(fa[x]):fa[x];}
inline ll read(){
	ll x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read(),cnt=m;
	for(ll i=1;i<=m;i++){
		int x=read(),y=read(),w=read();
		a[i]={x,y,w,0};
	}
	for(ll i=1;i<=k;i++){
		c[i]=read();
		for(ll j=1,y;j<=n;j++)
			y=read(),a[++cnt]={i,j,c[i]+y,1};
	}
	sort(a+1,a+cnt+1,cmp);
	for(ll i=0;i<(1<<k);i++){
		ll sum=0;
		for(ll j=1;j<=n;j++) fa[j]=j; 
		for(ll j=1;j<=k;j++) if(i>>(j-1)&1) sum+=c[j];
		for(ll j=1;j<=cnt;j++){
			if(a[j].flag&&(i>>(a[j].x-1)&1)) continue;
			ll x=find(fa[a[j].x]),y=find(fa[a[j].y]);
			if(x!=y) fa[x]=y,sum+=a[j].w;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
