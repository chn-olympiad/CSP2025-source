#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second 
using namespace std;
const int M=2e6+5;
const int N=1e4+5;
int n,m,k;
struct bian{
	int u,v,w;
	bool operator < (const bian &x) const{
		return w<x.w;
	} 
}e[M],a[11][N],b[M];
inline int rd(){
	int f=1,x=0;
	char ch;
	ch=getchar(); 
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar(); 
	} 
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar(); 
	}
	return x*f;
}
int c[15];
int fa[N];
int sz[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(sz[x]>sz[y]) swap(x,y);
	sz[y]+=sz[x];
	fa[x]=y;
}
inline ll kruskal(int m,int n){
	for(int i=1;i<=n+k;++i) fa[i]=i,sz[i]=1;
	ll ans=0;
	int cnt=0;
	for(int i=1,x,y;i<=m;++i){
		x=find(e[i].u),y=find(e[i].v);
		
		if(x==y) continue;
		ans+=e[i].w;
		++cnt;
		merge(e[i].u,e[i].v);
		if(cnt==n-1) break; 
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=m;++i){
		e[i].u=rd(),e[i].v=rd(),e[i].w=rd();
	}
	sort(e+1,e+m+1);
	if(!k){
		cout<<kruskal(m,n);
		return 0;
	}
	int cnt=n;
	bool flag1=1;
	for(int i=1;i<=k;++i){
		c[i]=rd();
		++cnt;
		bool flag=(c[i]==0);
		for(int j=1;j<=n;++j){
			 a[i][j].u=cnt,a[i][j].v=j,a[i][j].w=rd();
			 if(a[i][j].w==0) flag&=1;
		}
		flag1&=flag;
		sort(a[i]+1,a[i]+n+1);
	}
	if(flag1){
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				e[++m]=a[i][j];
			}
		}
		sort(e+1,e+m+1);
		cout<<kruskal(m,cnt);
		return 0;
	}else{
		ll res=1e18;
		ll ans;
		int tot,tot1;
		for(int i=1;i<=m;++i) b[i]=e[i];
		 for(int S=0;S<(1<<k);++S){
		 	ans=0;
		 	tot=m;
		 	tot1=n;
		 	for(int i=1;i<=m;++i){
		 		e[i]=b[i]; 
			} 
		 	for(int i=0;i<k;++i){
		 		if((S>>i)&1){
		 			for(int j=1;j<=n;++j){
		 				e[++tot]=a[i+1][j];
					}
					ans+=c[i+1];
					++tot1;
				 } 
			 }
			 sort(e+1,e+tot+1);
			 res=min(res,ans+kruskal(tot,tot1));
		 }
		 cout<<res;
	}
	
	return 0;
}
