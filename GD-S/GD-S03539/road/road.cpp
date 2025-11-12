#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,dd[10105],db,k,fy[15],fa[10105],bj[10105];
ll zbb(ll x){
	return fa[x]==x?x:fa[x]=zbb(fa[x]);
}
struct edge{
	ll q,z,bq,xg;
}ed[3000005];
void fjq(ll q,ll z,ll b){
	ed[++db]={q,z,b,dd[q]},dd[q]=db;
}
bool cmp(edge a,edge b){
	return a.bq<b.bq;
}
ll read(){
	ll s=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	ll aa,bb,cc;
	for(ll i=1;i<=m;i++){
		aa=read(),bb=read(),cc=read();
		fjq(aa,bb,cc);
	}
	for(ll i=1;i<=n;i++){
		bj[i]=1;
	}
	ll ans=0;
	
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(ed+1,ed+1+db,cmp);
	ll nb=0;
	for(ll i=1;i<=db;i++){
		ll qb=zbb(ed[i].q),zb=zbb(ed[i].z);
		if(qb!=zb){
			ans+=ed[i].bq;
			ed[++nb]=ed[i];
			fa[qb]=zb;
		}
	}
	db=nb;
	for(ll i=1;i<=k;i++){
		fy[i]=read();
		for(ll j=1;j<=n;j++){
			aa=read();
			fjq(j,i+n,aa);
		}
	}
	sort(ed+1,ed+1+db,cmp);
	for(ll ii=1;ii<=((1<<k)-1);ii++){
		ll da=0,dg=0;
		for(ll i=1;i<=k;i++){
			bj[n+i]=0;
		}
		for(ll i=1;i<=k;i++){
			if(ii&(1<<(i-1))){
				bj[n+i]=1,da+=fy[i];
//				cout<<n+i<<endl;
			}
		}
		for(ll i=1;i<=n+k;i++){
			fa[i]=i;
		}
		for(ll i=1;i<=db;i++){
			if(!bj[ed[i].q]||!bj[ed[i].z]){
				continue;
			}
			ll qb=zbb(ed[i].q),zb=zbb(ed[i].z);
			
			if(qb!=zb){
//				cout<<ed[i].q<<' '<<ed[i].z<<endl;
				da+=ed[i].bq;
				fa[qb]=zb;
			}
		}
		ans=min(ans,da);
//		cout<<"da:"<<da<<endl;
	}
	printf("%lld",ans);
	return 0;
}
