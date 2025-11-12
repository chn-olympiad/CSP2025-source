#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v;
	long long w;
}tmp[1000005],a[200005],doing[200005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int f[10015];
int find(int x){ 
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
long long dis[15][10005];
int c[15];
int n,m,k;
bool choose[15];
long long ans=0;
void mst(int cnt,long long t,int n){
	for(int i=1;i<=n;++i)f[i]=i;
	sort(doing+1,doing+cnt+1,cmp);
	int j=0;
	for(int i=1;i<=cnt;++i){
		int u=doing[i].u,v=doing[i].v;
		find(u);
		find(v);
		if(f[u]!=f[v]){
			t+=doing[i].w;
			f[f[u]]=f[v];
			++j;
		}
		if(j==n-1)break;
	}
	ans=min(ans,t);
	return;
}
void dfs(int x){
	if(x>k){
		int flag=0;
		int cnt=0;
		long long t=0;
		for(int i=1;i<=k;++i){
			if(choose[i]){
				++flag;
				for(int j=1;j<=n;++j){
					doing[++cnt].u=flag+n;
					doing[cnt].v=j;
					doing[cnt].w=dis[i][j];
				}
				t+=c[i];
			}
		}
		if(!flag)return;
		for(int i=1;i<n;++i){
			doing[++cnt].u=a[i].u;
			doing[cnt].v=a[i].v;
			doing[cnt].w=a[i].w;
		}
		mst(cnt,t,flag+n);
		return;
	}
	dfs(x+1);
	choose[x]=1;
	dfs(x+1);
	choose[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&tmp[i].u,&tmp[i].v,&tmp[i].w);
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]); 
		for(int j=1;j<=n;++j)scanf("%lld",&dis[i][j]);
	}
	sort(tmp+1,tmp+m+1,cmp);
	for(int i=1;i<=n;++i)f[i]=i;
	int cnt=0;
	for(int i=1;i<=m;++i){
		find(tmp[i].u);
		find(tmp[i].v);
		if(f[tmp[i].u]!=f[tmp[i].v]){
			ans+=tmp[i].w;
			f[f[tmp[i].u]]=f[tmp[i].v];
			a[++cnt].u=tmp[i].u,a[cnt].v=tmp[i].v,a[cnt].w=tmp[i].w;
		}
		if(cnt==n-1)break; 
	}
	dfs(1);
	cout<<ans;
	return 0;
}
