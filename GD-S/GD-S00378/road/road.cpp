#include<algorithm>
#include<iostream>
#include<cstdio>
#define ll long long
#define sco 2000000
using namespace std;
struct node{
	ll u,v,w;
}a[sco],b[sco];
ll n,m,k,now[sco],tmp,tot,ans,sum,in[sco],fa[sco],c[sco],mp[20][10010];
bool fl=1;
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void uni(ll x,ll y){
	fa[find(x)]=find(y);
}
bool cmp(node x,node y){return x.w<y.w;}
ll kru(ll tt){
	tmp=0;
	for(int i=1;i<=n+k;++i)fa[i]=i;
	sort(b+1,b+1+tt,cmp);
	for(int i=1;i<=tt;++i){
		if(find(b[i].u)!=find(b[i].v)){
			uni(b[i].u,b[i].v);
			if(in[b[i].u]==0)in[b[i].u]=b[i].w;
			else in[b[i].u]=-1;
			if(in[b[i].v]==0)in[b[i].v]=b[i].w;
			else in[b[i].v]=-1;
			tmp+=b[i].w;
		}
	}
	return tmp;
	return 0;
}
bool wk(ll x){
	tot=m+n;
	for(int i=1;i<=n;++i){
		b[i+m]=(node){x+n,i,mp[x][i]};
	}
	ll tmp=kru(tot);
	if(tmp+c[x]+sum<ans+sum){
		m+=n;
		sum+=c[x];
		ans=tmp;
		return true;
	}
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		b[i]=a[i];
	}
	for(int i=1;i<=k;++i){
		scanf("%lld",c+i);
		sum+=c[i];
		for(int j=1;j<=n;++j){
			scanf("%lld",mp[i]+j);
		}
	}
	if(!sum){
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				b[++m]=(node){i+n,j,mp[i][j]};
			}
		}
		ll tmp=0;
		for(int i=n+1;i<=n+k;++i){
			if(in[i]>0)tmp-=in[i];
		}
		printf("%lld",kru(m)-tmp);
		return 0;
	}
	tot=m;
	ans=kru(m);
	sum=0;
	for(int i=1;i<=k;++i){
		if(wk(i)){
			m=tot;
		}
	}
	printf("%lld\n",ans+sum);
	return 0;
}
