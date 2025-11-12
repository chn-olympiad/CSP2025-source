#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,ans,a[N][5];
int vis[5];
inline void dfs(int d,int su){
	if(d>n){ans=max(ans,su);return;}
	for(int j=1;j<=3;++j)
	if(vis[j]<(n>>1))++vis[j],
	dfs(d+1,su+a[d][j]),--vis[j];
}
inline void dfs2(int d,int su){
	if(d>n){ans=max(ans,su);return;}
	for(int j=1;j<=2;++j)
	if(vis[j]<(n>>1))++vis[j],
	dfs(d+1,su+a[d][j]),--vis[j];
}
struct node{
	int i,j,w;
}e[N];
bool cmp(node a,node b){
	return a.w>b.w;
}
bool vi[N];
int vj[N],p;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		bool f=1,f2=1;ans=0,p=0;
		memset(vis,0,sizeof vis);
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=3;++j){
			scanf("%lld",&a[i][j]),
			e[++p]={i,j,a[i][j]};
			if(a[i][2])f=0;
			if(a[i][3])f=f2=0;
		}
		if(f||n>17){
			sort(e+1,e+p+1,cmp);
			for(int k=1;k<=p;++k){
				int i=e[k].i,j=e[k].j,w=e[k].w;
				if(!vi[i]&&vj[j]<(n>>1))
				vi[i]=1,++vj[j],ans+=w;
			}
			memset(vi,0,sizeof vi);
			memset(vj,0,sizeof vj);
		}
		else if(f2)dfs2(1,0);
		else dfs(1,0);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0; 
} 
