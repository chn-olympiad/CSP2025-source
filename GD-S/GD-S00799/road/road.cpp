#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mk(x,y) make_pair(x,y)
const int M=1e6+10,N=1e4+100;
int n,m,k;
struct EDGE{
	int u,v,w;
}e[M],add[M],ls[M]; 
inline bool cmp_E(const EDGE&A,const EDGE&B){
	return A.w<B.w;
}
int c[11],a[11][N];
int cnt=0;
ll ans=1e18;
int fa[N],d[N];
inline int find(int k){
	if(k==fa[k])return k;
	return fa[k]=find(fa[k]);
}
inline bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return false;
	if(d[fx]>d[fy])swap(fx,fy);
	fa[fx]=fy;
	d[fy]+=(d[fx]==d[fy]); 
	return true;
}
inline void dfs(int u,ll sum){
	if(u==k+1){
		ll res=sum;
		for(int i=1;i<=cnt;i++)ls[i]=add[i];
		for(int i=1;i<=n+k;i++)fa[i]=i,d[i]=1;
		sort(ls+1,ls+cnt+1,cmp_E);
		int i=1,j=1;
		while(i<=m||j<=cnt){
			if(i>m){
				int x=ls[j].u,y=ls[j].v,w=ls[j].w;
				bool pd=merge(x,y);
				if(pd)res+=w;
				j++;
			}else if(j>cnt){
				int x=e[i].u,y=e[i].v,w=e[i].w;
				bool pd=merge(x,y);
				if(pd)res+=w;
				i++;
			}else{
				if(e[i].w<ls[j].w){
					int x=e[i].u,y=e[i].v,w=e[i].w;
					bool pd=merge(x,y);
					if(pd)res+=w;
					i++;
				}else{
					int x=ls[j].u,y=ls[j].v,w=ls[j].w;
					bool pd=merge(x,y);
					if(pd)res+=w;
					j++;
				}
			}
			if(res>=ans)break;
		}
		ans=min(ans,res);
		return;
	}
	for(int i=1;i<=n;i++)add[++cnt]=EDGE{n+u,i,a[u][i]};
	dfs(u+1,sum+c[u]);
	cnt-=n;
	dfs(u+1,sum); 
	
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	sort(e+1,e+m+1,cmp_E);
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
