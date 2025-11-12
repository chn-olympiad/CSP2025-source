#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5,K=15;
const ll INF=9223372036854775807ll;
int n,m,k,v[K],vis[N+K],cnt;
struct edge{
	int u,v,w;
}a[M+N*K];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[N+K],siz[N+K];
int Find(int u){
	if(fa[u]==u)return u;
	return fa[u]=Find(fa[u]);
}
void Merge(int u,int v){
	u=Find(u),v=Find(v);
	if(u==v)return;
	if(siz[u]>siz[v])swap(u,v);
	fa[u]=v;
	siz[v]+=siz[u];
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[++cnt]=(edge){u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		int w;
		for(int j=1;j<=n;j++){
			cin>>w;
			a[++cnt]=(edge){i+n,j,w};
		}
	}
	sort(a+1,a+cnt+1,cmp);
	ll ans=INF;
	for(int i=1;i<=n;i++)vis[i]=1;
	for(int I=0;I<(1<<k);I++){
		ll sum=0;
		int Sum=n-1;
		for(int i=1;i<=k;i++)vis[i+n]=((I>>(i-1))&1);
		for(int i=1;i<=k;i++)if(vis[i+n]){
			sum+=v[i];
			Sum++;
		}
		if(sum>=ans)continue;
		for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
		for(int i=1;i<=cnt;i++)if(vis[a[i].u]&&vis[a[i].v]&&Find(a[i].u)!=Find(a[i].v)){
			sum+=a[i].w;Sum--;
			if(Sum==0)break;
			if(sum>=ans){
				sum=-1;
				break;
			}
			Merge(a[i].u,a[i].v);
		}
		if(sum==-1)continue;
//		cout<<I<<": "<<sum<<"\n";
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
