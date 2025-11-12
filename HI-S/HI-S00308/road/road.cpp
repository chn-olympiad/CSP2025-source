#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y;
long long z;
long long a[12][10101];
long long c[12];
int fa[2010110];
long long ans;
struct rec{
	int u,v;
	long long w;
}e[2011010];
bool cmp(rec g,rec h){
	return g.w<h.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=2000005;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&x,&y,&z);
		e[++cnt].u=x,e[cnt].v=y,e[cnt].w=z;
	}
	int ret=0,ret1=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0)ret++;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0)ret1++;
		}
	}
	if(ret==k&&ret1==n*k){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long mi=1e14;
			for(int g=1;g<=k;g++){
				mi=min(mi,c[g]+a[g][i]+a[g][j]);
			}
			e[++cnt].u=i,e[cnt].v=j,e[cnt].w=mi;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int cou=0;
	for(int i=1;i<=cnt;i++){
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(cou==n-1)break;
		if(fx!=fy){
			fa[fx]=fy;
			ans+=e[i].w;
			cou++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
