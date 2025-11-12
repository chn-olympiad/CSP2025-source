#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,pair<int,int> >
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline ll read(){
	int k=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {k=(k<<1)+(k<<3)+ch-48;ch=getchar();}
	return k*f;
}
int n,m,k;
const int N=1e4+27,M=1e6+7;
int fa[N],siz[N];
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool check(){
	int faa=find(1);
	for(int i=2;i<=n;i++)
		if(find(i)!=faa) return 0;
	return 1;
}
int c[N],tot;
bool vis[15],used[N];
priority_queue <pii,vector<pii>,greater<pii> > q;
vector <int> dis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		q.push(mk(w,mk(u,v)));
	}
	for(int i=1;i<=k;i++){
		c[i+n]=read();
		for(int j=1;j<=n;j++) {
			dis[i+n].push_back(read());
			q.push(mk(dis[i+n][j-1]+c[i+n],mk(i+n,j)));
		}
	}
	ll ans=0;
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
	while(!check()){
		pii x=q.top();
		q.pop();
		int u=x.se.fi,v=x.se.se;
		ll w=x.fi;
		if(u>n){
			if(!used[u]){
				used[u]=1;
				for(int i=1;i<=n;i++)
					if(i!=v) q.push(mk(dis[u][i-1],mk(u,i)));
			}
		}
		u=find(u),v=find(v);
		if(u==v) continue;
		ans+=w;
		fa[v]=u;
	}
	printf("%lld",ans);
	return 0;
}
