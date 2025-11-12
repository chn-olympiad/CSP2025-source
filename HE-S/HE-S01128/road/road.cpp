
// Surpassing never ends!

#include<bits/stdc++.h>
#define ll long long
//#define int long long 
using namespace std;
const int N=2e4+500,M=1e6+100;
int read() {
	int x=0;
//	cin>>x;return x;
	short f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-')f=-1;c=getchar(); }
	while(c>='0'&&c<='9') { x=x*10+c-'0';c=getchar(); }
	return x*f;
}
bool MB_1;

int n,m,k,c[N],cnt;
ll ans;

struct Edge { int u,v,w; }e[M],a[11][N],b[N],la[11][N];
bool cmp(Edge a,Edge b) { return a.w<b.w; }

int fa[N];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
void init() { for(int i=1;i<=n+k;i++) fa[i]=i; }


void dfs(int nw,int s,int sz) {
	ll res=0;
	for(int i=1;i<=k;i++) if((s>>i)&1) res+=c[i];
	for(int i=1;i<=sz;i++) la[nw][i]=b[i];
	
	int i1=1,j=1,ct=0;
	while(i1<=sz&&j<=n) {
		if(la[nw][i1].w<=a[nw][j].w) b[++ct]=la[nw][i1],i1++;
		else b[++ct]=a[nw][j],j++;
	}
	while(i1<=sz) b[++ct]=la[nw][i1],i1++;
	while(j<=n) b[++ct]=a[nw][j],j++;
	ct=0;
	init();
	for(int i=1;;i++) {
		int f1=find(b[i].u),f2=find(b[i].v);
		if(f1==f2) continue;
		else {
			res+=b[i].w;
			a[0][++ct]=b[i];
			fa[f1]=f2;
			if(ct==sz+1) break;
		}
	}
	
	ans=min(ans,res+c[nw]);
	
	if(nw==k) return ;
	for(int i=1;i<=ct;i++) b[i]=a[0][i]; 
	dfs(nw+1,s|(1<<nw),sz+1);
	for(int i=1;i<=sz;i++) b[i]=la[nw][i];
	dfs(nw+1,s,sz);
	
	return ;
}

bool MB_2;

signed main() {
//	cerr<<fabs(&MB_2-&MB_1)/(1024*1024)<<"MB\n";
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) e[i]={read(),read(),read()};
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]={i+n,j,read()}; 
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++) sort(a[i]+1,a[i]+1+n,cmp);
	
	init();
	cnt=0;
	for(int i=1;i<=m;i++) {
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2) continue;
		else {
			ans+=e[i].w;
			b[++cnt]=e[i];
			fa[f1]=f2;
			if(cnt==n-1) break;
		}
	}
	dfs(1,0,n-1);
	cout<<ans;
	return 0;
}
