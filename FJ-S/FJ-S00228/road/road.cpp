#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
const int M=1e6+5;
const int K=11;
const ll inf=1e18;
int n,m,k;
struct Edge{
	int u,v,w;
	bool operator <(const Edge p) const{
		return w<p.w;
	}
}E[M],e[K][M];
int c[K],a[K][N];
int p[K];
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void solve1(){
	ll ans=inf;
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<=k;j++) p[j]=1;
		for(int j=1;j<=n;j++) fa[j]=j;
		ll res=0,cnt=0;
		for(int j=1;j<=k;j++)
			if(i>>(j-1)&1) res+=c[j];
		while(cnt<n-1){
			int mn=(p[0]<=m ? E[p[0]].w : inf),id=0;
			for(int j=1;j<=k;j++){
				if(!(i>>(j-1)&1)) continue;
				if(p[j]>n-1) continue;
				int val=e[j][p[j]].w;
				if(val<mn){
					mn=val;
					id=j;
				}
			}
			int u=(id ? e[id][p[id]].u : E[p[0]].u),v=(id ? e[id][p[id]].v : E[p[0]].v),w=mn;
			p[id]++;
			u=find(u),v=find(v);
			if(u!=v){
	//			cout<<id<<" "<<p[id]-1<<"\n";
				fa[v]=u;
				res+=w;
				cnt++;
				if(cnt==n-1) break;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
void solve2(){
	for(int j=0;j<=k;j++) p[j]=1;
	for(int j=1;j<=n;j++) fa[j]=j;
	ll ans=0,cnt=0;
	while(cnt<n-1){
		int mn=(p[0]<=m ? E[p[0]].w : inf),id=0;
		for(int j=1;j<=k;j++){
			if(p[j]>n-1) continue;
			int val=e[j][p[j]].w;
			if(val<mn){
				mn=val;
				id=j;
			}
		}
		int u=(id ? e[id][p[id]].u : E[p[0]].u),v=(id ? e[id][p[id]].v : E[p[0]].v),w=mn;
		p[id]++;
		u=find(u),v=find(v);
		if(u!=v){
//			cout<<id<<" "<<p[id]-1<<"\n";
			fa[v]=u;
			ans+=w;
			cnt++;
			if(cnt==n-1) break;
		}
	}
	cout<<ans<<"\n";
}
void solve3(){
	for(int j=0;j<=k;j++) p[j]=1;
	for(int j=1;j<=n;j++) fa[j]=j;
	ll ans=0,cnt=0;
	while(cnt<n-1){
		int mn=(p[0]<=m ? E[p[0]].w : inf),id=0;
		for(int j=1;j<=k;j++){
			if(p[j]>n-1) continue;
			int val=e[j][p[j]].w+(p[j]>1 ? 0 : c[j]);
			if(val<mn || (val==mn && p[j]==1)){
				mn=val;
				id=j;
			}
		}
		int u=(id ? e[id][p[id]].u : E[p[0]].u),v=(id ? e[id][p[id]].v : E[p[0]].v),w=mn;
		p[id]++;
		u=find(u),v=find(v);
		if(u!=v){
//			cout<<id<<" "<<p[id]-1<<"\n";
			fa[v]=u;
			ans+=w;
			cnt++;
			if(cnt==n-1) break;
		}
	}
	cout<<ans<<"\n";
}
void solve4(){
	for(int i=1;i<=k;i++){
		int tot=0;
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				e[i][++tot]={u,v,a[i][u]+a[i][v]};
		sort(e[i]+1,e[i]+tot+1);
	}
	ll ans=inf;
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<=k;j++) p[j]=1;
		for(int j=1;j<=n;j++) fa[j]=j;
		ll res=0,cnt=0;
		for(int j=1;j<=k;j++)
			if(i>>(j-1)&1) res+=c[j];
		while(cnt<n-1){
			int mn=(p[0]<=m ? E[p[0]].w : inf),id=0;
			for(int j=1;j<=k;j++){
				if(!(i>>(j-1)&1)) continue;
				if(p[j]>n*(n-1)/2) continue;
				int val=e[j][p[j]].w;
				if(val<mn){
					mn=val;
					id=j;
				}
			}
			int u=(id ? e[id][p[id]].u : E[p[0]].u),v=(id ? e[id][p[id]].v : E[p[0]].v),w=mn;
			p[id]++;
			u=find(u),v=find(v);
			if(u!=v){
	//			cout<<id<<" "<<p[id]-1<<"\n";
				fa[v]=u;
				res+=w;
				cnt++;
				if(cnt==n-1) break;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
void solve5(){
	for(int i=1;i<=k;i++){
		int tot=0;
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				e[i][++tot]={u,v,a[i][u]+a[i][v]};
		sort(e[i]+1,e[i]+tot+1);
	}
	for(int j=0;j<=k;j++) p[j]=1;
	for(int j=1;j<=n;j++) fa[j]=j;
	ll ans=0,cnt=0;
	while(cnt<n-1){
		int mn=(p[0]<=m ? E[p[0]].w : inf),id=0;
		for(int j=1;j<=k;j++){
			if(p[j]>n*(n-1)/2) continue;
			int val=e[j][p[j]].w;
			if(val<mn){
				mn=val;
				id=j;
			}
		}
		int u=(id ? e[id][p[id]].u : E[p[0]].u),v=(id ? e[id][p[id]].v : E[p[0]].v),w=mn;
		p[id]++;
		u=find(u),v=find(v);
		if(u!=v){
//			cout<<id<<" "<<p[id]-1<<"\n";
			fa[v]=u;
			ans+=w;
			cnt++;
			if(cnt==n-1) break;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		E[i]={u,v,w};
	}
	sort(E+1,E+1+m);
	bool flg=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		flg&=(!c[i]);
		int mn=1e9,p=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]<mn){
				mn=a[i][j];
				p=j;
			}
		}
		for(int j=1;j<=n;j++)
			if(j!=p) e[i][j-(j>=p)]={p,j,mn+a[i][j]};
		sort(e[i]+1,e[i]+n);
	}
//	for(int i=1;i<=m;i++)
//		printf("0:(%lld,%lld,%lld)\n",E[i].u,E[i].v,E[i].w);
//	for(int i=1;i<=k;i++)
//		for(int j=1;j<n;j++)
//			printf("%lld:(%lld,%lld,%lld)\n",i,e[i][j].u,e[i][j].v,e[i][j].w);
	if(k==0) solve1();
	else if(flg){
		if(n*n*k<=(int)(3e8)) solve5();
		else solve2();
	}
	else if(n*n*k*(1ll<<k)<=(int)(3e8)) solve4();
	else if(k<=6) solve1();
	else solve3();
	return 0;
}
