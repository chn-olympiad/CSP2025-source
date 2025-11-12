#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,u,v,w,p[11],c[11],fa[20001];
ll ans=1e18;
int find(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
struct node{
	int u,v,w;
	node(int x=0,int y=0,int z=0){u=x,v=y,w=z;}
	bool operator<(const node &k)const{return w<k.w;}
}e[11][10001],f[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&u,&v,&w),f[i]=node(u,v,w);
	sort(f+1,f+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,j=0;i<=m;i++) if(find(f[i].u)!=find(f[i].v)) fa[find(f[i].u)]=find(f[i].v),e[0][++j]=f[i];
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&w),e[i][j]=node(i+n,j,w);
		sort(e[i]+1,e[i]+1+n);
	}
	e[0][n]=node(1,1,1e9);
	for(int s=0;s<(1<<k);s++){
		ll sum=0;
		int cnt=0;
		for(int i=1;i<=k;i++) if(s>>(i-1)&1) sum+=c[i],cnt++;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=0;i<=k;i++) p[i]=1;
		for(int i=1;i<n+cnt;i++){
			int x=-1,now=1e9;
			for(int j=0;j<=k;j++){
				if(j&&!(s>>(j-1)&1)) continue;
				while(p[j]<=n&&find(e[j][p[j]].u)==find(e[j][p[j]].v)) p[j]++;
				if(p[j]<=n&&e[j][p[j]].w<=now) x=j,now=e[j][p[j]].w;
			}
			sum+=now;
			fa[find(e[x][p[x]].u)]=find(e[x][p[x]].v);
			p[x]++;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
