#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=1e4+5,M=1e6+5,K=12;
int n,m,k,c[K],a[K][N],fa[N*K],cnte,mm,ans,res;
bool flagA=1;
struct node{
	int u,v,w;
}e[M],g[M+N*K],e2[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
inline int find(int x){
	return fa[x]^x?fa[x]=find(fa[x]):x;
}
inline void init(){
	for(int i=1;i<=n*k+n;i++)fa[i]=i;
	for(int i=1;i<=mm;i++)g[i]=e2[i];
}
inline void init2(){
	for(int i=1;i<=n*k+n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)g[i]=e[i];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;init();
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];flagA&=(!c[i]);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(flagA){
		for(int sum=(1<<k)-1;sum<(1<<k);sum++){
			int cnt=m,cntp=n;res=0;init2();
			for(int i=0;i<k;i++){
				res+=c[i+1];cntp++;
				for(int j=1;j<=n;j++){
					g[++cnt]={cntp,j,a[i+1][j]};
				}
			}sort(g+1,g+1+cnt,cmp);cnte=0;
			for(int i=1,u,v;i<=cnt;i++){
				u=g[i].u,v=g[i].v;u=find(u),v=find(v);
				if(u==v)continue;fa[u]=v;cnte++;res+=g[i].w;
				if(cnte+1==cntp)break;
			}ans=res;//cout<<res<<'\n';
		}cout<<ans;return 0;
	}
	for(int i=1,u,v;i<=m;i++){
		u=e[i].u,v=e[i].v;u=find(u),v=find(v);
		if(u==v)continue;fa[u]=v;cnte++;ans+=e[i].w;e2[++mm]=e[i];
		if(cnte+1==n)break;
	}
	for(int sum=1;sum<(1<<k);sum++){
		int tmp=sum,cnt=mm,cntp=n;res=0;init();
		for(int i=0;i<k;i++){
			if((tmp>>i)&1){
				res+=c[i+1];cntp++;
				for(int j=1;j<=n;j++){
					g[++cnt]={cntp,j,a[i+1][j]};
				}
			}
		}sort(g+1,g+1+cnt,cmp);cnte=0;
		for(int i=1,u,v;i<=cnt;i++){
			u=g[i].u,v=g[i].v;u=find(u),v=find(v);
			if(u==v)continue;fa[u]=v;cnte++;res+=g[i].w;
			if(cnte+1==cntp)break;
		}ans=min(ans,res);//cout<<res<<'\n';
	}cout<<ans;
	return 0;
}
