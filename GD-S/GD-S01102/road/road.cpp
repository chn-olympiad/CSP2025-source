#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5,M=1e6+5,K=15;
ll n,m,k,fa[N],cnt,c[K],a[K][N],ps[K];
struct node{ll x,y,d;}e[M],p[M],vl[N];
bool cmp(node x,node y){return x.d<y.d;}
void read(ll &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return ;
}
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(ll i=1;i<=m;i++)
	read(e[i].x),read(e[i].y),read(e[i].d);
	sort(e+1,e+m+1,cmp);
	for(ll i=1;i<=n;i++)fa[i]=i;
	ll ss=0;
	for(ll i=1;i<=m;i++){
		ll tx=find(e[i].x),ty=find(e[i].y);
		if(tx!=ty){
			fa[tx]=ty;
			vl[++cnt]=e[i];
			ss++;
			if(ss==n-1)break;
		}
	}
	for(ll i=1;i<=k;i++){
		read(c[i]);
		for(ll j=1;j<=n;j++)
		read(a[i][j]);
	}
	ll maxn=(1<<k)-1;
	ps[0]=1;
	for(ll i=1;i<K;i++)
	ps[i]=(ps[i-1]<<1);
	ll pos;
	ll ans=1e18;
	for(ll s=0;s<=maxn;s++){
		pos=cnt;
		ll sum=0,tot=0;
		for(ll i=1;i<=cnt;i++)
		p[i]=vl[i];
		for(ll i=1;i<=k;i++){
			if((s&ps[i-1])==0)
			continue;
			tot++;
			sum+=c[i];
			for(ll j=1;j<=n;j++)
			p[++pos]=(node){i+n,j,a[i][j]};
		}
		sort(p+1,p+pos+1,cmp);
		ll l=0;
		for(ll i=1;i<=n+k;i++)fa[i]=i;
		for(ll i=1;i<=pos;i++){
			ll tx=find(p[i].x),ty=find(p[i].y);
			if(tx!=ty){
				fa[tx]=ty;
				sum+=p[i].d;
				l++;
				if(sum>=ans)break;
				if(l==n+tot-1)
				break;
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
