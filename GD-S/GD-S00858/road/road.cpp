#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second 
#define rep(t,l,r) for(int t=l;t<=r;t++)
#define per(t,l,r) for(int t=r;t>=l;t--)

using namespace std;
const int N=1e4+50,M=1e6+50;
int n,m,k,fa[N],tot,sz[N],id[20];
ll c[N];
struct edge{int u,v; ll w;} e[M],tmp[N*10];
pii val[15][N];
bool cmp(edge a,edge b) {return a.w<b.w;}
int find(int x) {return ((fa[x]==x)?x:fa[x]=find(fa[x]));}

template<typename T> void read(T &x) {
	x=0; bool op=false; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') op=true; ch=getchar();}
	while(ch<='9'&&ch>='0') {x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	if(op) x=-x; return ;
}

signed main() {
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	read(n); read(m); read(k); 
	rep(i,1,m) read(e[i].u),read(e[i].v),read(e[i].w);
	rep(i,1,k) {
		read(c[i]); 
		rep(j,1,n) {read(val[i][j].fi); val[i][j].se=j;}
		sort(val[i]+1,val[i]+n+1);
	}
	sort(e+1,e+m+1,cmp); ll ans=0x3f3f3f3f3f3f3f3f;
	rep(i,0,(1<<k)-1) {
		rep(i,1,n+k) fa[i]=i,sz[i]=1;
		rep(i,1,k) id[i]=0;
		ll cur_ans=0; tot=0;
		rep(j,0,k-1) if((i>>j)&1) {
			cur_ans+=c[j+1]; 
			rep(x,1,n) tmp[++tot]=(edge){j+1+n,val[j+1][x].se,val[j+1][x].fi};
		}
		if(cur_ans>ans) continue;
		sort(tmp+1,tmp+tot+1,cmp);
		int p=0,ct=0,rn=0;
		while(ct<n+tot-1) {
			rn++;
			int mn=0x3f3f3f3f;
			bool flg=false;
			rep(x,1,k) if(((i>>(x-1))&1)&&id[x]+1<=n) flg=true;
			if(!flg) break;
			rep(x,1,k) if(((i>>(x-1))&1)&&id[x]+1<=n) mn=min(mn,val[x][id[x]+1].fi);
			while(p+1!=m&&ct<n+tot-1&&e[p+1].w<=mn) {
				int u=find(e[p+1].u),v=find(e[p+1].v);
				if(u!=v) {
					if(sz[u]<sz[v]) swap(u,v);
					fa[v]=u; sz[u]+=sz[v];
					cur_ans+=e[p+1].w; ct++;
				}
				p++;
			}
			if(ct>=n+tot-1) break;
			rep(x,1,k) if(((i>>(x-1))&1)&&id[x]+1<=n&&val[x][id[x]+1].fi==mn&&ct<n+tot-1) {
				int u=find(n+x),v=find(val[x][id[x]+1].se);
				if(u!=v) {
					if(sz[u]<sz[v]) swap(u,v);
					fa[u]=v; sz[u]+=sz[v];
					cur_ans+=val[x][id[x]+1].fi; ct++;
				}
				id[x]++;
			}
			if(ct>=n+tot-1) break;
		}
		while(p+1!=m&&ct<n+tot-1) {
			int u=find(e[p+1].u),v=find(e[p+1].v);
			if(u!=v) {
				ct++;
				if(sz[u]<sz[v]) swap(u,v);
				fa[v]=u; sz[u]+=sz[v];
				cur_ans+=e[p+1].w;
			}
			p++;
		}
		ans=min(ans,cur_ans);
	}
	cout<<ans<<"\n";
	return 0;
}
