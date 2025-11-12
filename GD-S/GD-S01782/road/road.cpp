#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+44,M=1e6+66;
//bool mst; 
int n,m,k,tot,tp,c[13];
int fa[N],siz[N];
struct Node{
	int w,id;
}a[13][N];
struct Edge{
	int u,v,w;
}E[M],Et[N],tmp[N*13],tmp1[N*13];

bool cmp(Edge x,Edge y){
	return x.w<y.w;
}

bool cmp1(Node x,Node y){
	return x.w<y.w;
}

void init(int _n){
	for(int i=0;i<=_n;++i) fa[i]=i,siz[i]=1; // 
}
int find(int x){
	return fa[x]=fa[x]==x?fa[x]:find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	if(siz[fx]>siz[fy]) swap(fx,fy);
	siz[fy]+=siz[fx]; fa[fx]=fy;
}

void upd(int id){
	for(int i=1;i<=tp;++i) tmp1[i]=tmp[i];
	int t=tp; tp=0;
	int i=1,j=1;
	for(;i<=t&&j<=n;){
//		if(i<=t&&j<=n){
		if(tmp1[i].w<a[id][j].w) tmp[++tp]=tmp1[i],++i;
		else tmp[++tp]={n+id,a[id][j].id,a[id][j].w},++j;
//		}
//		else if(i<=t){
//			tmp[++tp]=tmp1[i]; ++i;
//		}else if(j<=n){
//			tmp[++tp]={n+id,a[id][j].id,a[id][j].w}; ++j;
//		}
	}
	while(i<=t) tmp[++tp]=tmp1[i],++i;
	while(j<=n) tmp[++tp]={n+id,a[id][j].id,a[id][j].w},++j;
//	merge(tmp1+1,tmp1+tp+1,a[id]+1,a[id]+n+1,tmp+1);
//	tp+=n;
}

//bool med;

int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar(); }
	while(ch>='0'&&ch<='9'){ x=x*10+ch-48;ch=getchar(); }
	return x*f;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("t2.in","r",stdin);
//	freopen("road4.in","r",stdin);
//	cerr<<((&med)-(&mst))/1024.0/1024.0<<'\n';
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin>>n>>m>>k;
	n=read(); m=read(); k=read();
	for(int i=1;i<=m;++i){
//		cin>>E[i].u>>E[i].v>>E[i].w;
		E[i]={read(),read(),read()};
	}
	for(int i=1;i<=k;++i){
//		cin>>c[i];
		c[i]=read();
		for(int j=1;j<=n;++j) a[i][j].w=read(),a[i][j].id=j;
	}
	for(int i=1;i<=k;++i) sort(a[i]+1,a[i]+n+1,cmp1);
	sort(E+1,E+m+1,cmp);
	ll ans=0;
	init(n+11);
	for(int i=1;i<=m&&tot<n-1;++i){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(find(u)==find(v)) continue;
		Et[++tot]=E[i];
		ans+=w;
		merge(u,v);
	}
	for(int i=1;i<(1<<k);++i){
		ll res=0; int tt=n-1; tp=0;
		for(int j=1;j<=tot;++j) tmp[++tp]=Et[j];
		for(int j=0;j<k;++j){
			if((i>>j)&1) upd(j+1),res+=c[j+1],++tt; 
		}
		init(n+11);
		for(int j=1,te=0;j<=tp&&te<tt;++j){
			int u=tmp[j].u,v=tmp[j].v,w=tmp[j].w;
			if(find(u)==find(v)) continue;
			res+=w; ++te;
			merge(u,v);
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
//	cout<<ans;
	return 0;
}
