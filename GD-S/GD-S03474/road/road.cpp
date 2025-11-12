#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=20005,M=1000005,K=15;
int n,m,k,ec,a[K][N],c[N];
tuple<int,int,int>e[M],f[M],g[M],h[M];
long long r;
struct dsu{
	int fa[N],s[N];
	void init(int n){
		for(int i=1;i<=n;i++)fa[i]=i,s[i]=1;
	}
	int query(int x){
		if(fa[x]==x)return x;
		return fa[x]=query(fa[x]);
	}
	void add(int x,int y){
		int qx=query(x),qy=query(y);
		if(qx!=qy){
			if(s[qx]<s[qy]){
				fa[qx]=qy;
				s[qy]+=s[qx];
			}else{
				fa[qy]=qx;
				s[qx]+=s[qy];
			}
		}
	}
}d;
inline void check(int S){
	long long sum=0,s=0,nk=n-1;
	for(int i=1;i<n;i++)g[i]=f[i];
	for(int i=1;i<=k;i++){
		if(S&(1ll<<i-1)){
			ec=0;
			sum+=c[i];
			s=0;
			d.init(n+k);
			for(int j=nk+1;j<=nk+n;j++){
				g[j]=make_tuple(a[i][j-nk],n+i,j-nk);
			}
			sort(g+1,g+nk+n+1);
			for(int j=1;j<=nk+n;j++){
				int u,v,w;
				tie(w,u,v)=g[j];
				if(d.query(u)==d.query(v))continue;
				d.add(u,v);
				s+=w; 
				h[++ec]=g[j];
				if(ec==nk+1)break; 
			}
			for(int j=1;j<=nk+1;j++)g[j]=h[j];
			++nk;
		}
	}
	r=min(r,sum+s);
}
signed main(){
#ifndef XYZ
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]=make_tuple(w,u,v);
	}
	sort(e+1,e+m+1);
	d.init(n);
	for(int i=1;i<=m;i++){
		int u,v,w;
		tie(w,u,v)=e[i];
		if(d.query(u)==d.query(v))continue;
		d.add(u,v);
		f[++ec]=e[i];
		r+=w;
	}
	for(int i=1;i<n;i++)e[i]=f[i];
	m=ec;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=1;i<(1<<k);i++)check(i);
	cout<<r;
	return 0;
}


