//GZ-S00488 遵义市第四中学 雍大有 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10005,M=1000005,K=15,inf=100000000000;
ll n,m,k,dis[N+K],c[K],a[K][N];
bitset<N+K> vis;
vector<pair<ll,ll> > G[N+K];
void f_read(ll &x){
	x=0;
	bool w=0;
	char ch=0;
	while(!isdigit(ch)){
		if(ch=='-')w=1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	if(w)x=-x;
}
void f_write(ll x){
	static int sta[65];
	int top=0;
	if(x<0){
		x=-x;
		putchar('-');
	}
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(sta[--top]+'0');
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool typ=1;
	f_read(n);
	f_read(m);
	f_read(k);
	for(int i=1;i<=m;++i){
		ll u,v,w;
		f_read(u);
		f_read(v);
		f_read(w);
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;++i){
		f_read(c[i]);
		if(typ&&c[i])typ=0;
		bool tpn=0;
		for(int j=1;j<=n;++j){
			f_read(a[i][j]);
			if(!tpn&&!a[i][j])tpn=1;
		}
		if(typ&&!tpn)typ=0;
	}
	if(typ||k==0){
		ll ans=0,cnt=1;
		dis[1]=0,vis[1]=1;
		for(int i=2;i<=n+k;++i)dis[i]=inf;
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				G[n+i].push_back(make_pair(j,a[i][j]));
				G[j].push_back(make_pair(n+i,a[i][j]));
			}
		}
		for(int i=0;i<(int)G[1].size();++i){
			ll u=G[1][i].first,w=G[1][i].second;
			dis[u]=min(dis[u],w);
		}
		while(cnt!=n+k){
			ll mi=inf,mip=0;
			for(int i=1;i<=n+k;++i){
				if(vis[i])continue;
				if(dis[i]<mi){
					mi=dis[i];
					mip=i;
				}
			}
			vis[mip]=1,++cnt,ans+=mi;
			for(int i=0;i<(int)G[mip].size();++i){
				ll u=G[mip][i].first,w=G[mip][i].second;
				if(vis[u])continue;
				dis[u]=min(dis[u],w);
			}
		}
		f_write(ans);
	}
	return 0;
}
