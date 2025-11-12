#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e4+10,M=1e6+10,K=11;
int n,m,k,cnt;
struct edge{
	int x,y;
	ll z;
}g[M];
struct edge2{
	int x,y;
	ll z;
	int id;
}g2[M];
ll sum[N];
int f[N],vis[N],siz[N];
inline bool cmp(edge a,edge b){
	return a.z<b.z;
}
inline bool cmp1(edge2 a,edge2 b){
	return a.z<b.z;
}
inline int _find(int x){
	if(x==f[x]) return x;
	return f[x]=_find(f[x]);
}
struct node{
	int id;
	ll val;
}w[K][N];
inline bool cmp2(node a,node b){
	return a.val<b.val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&g[i].x,&g[i].y,&g[i].z);
	sort(g+1,g+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int f1=_find(g[i].x),f2=_find(g[i].y);
		if(f1==f2) continue;
		f[f1]=f2,g[++cnt]=g[i],ans+=g[i].z;
		if(cnt==n-1) break;
	}
	cnt=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&sum[i]);
		for(int j=1;j<=n;j++){
			w[i][j].id=j;
			scanf("%lld",&w[i][j].val);
		}
		sort(w[i]+1,w[i]+1+n,cmp2);
		for(int j=2;j<=n;j++){
			g2[++cnt]=(edge2){w[i][1].id,w[i][j].id,w[i][j].val,i};
		}
	}
	sort(g2+1,g2+1+cnt,cmp1);
	int S=(1<<k)-1; 
	for(int s=1;s<=S;s++){
		ll val=0;
		for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1) vis[i]=1,val+=sum[i]+w[i][1].val;
			else vis[i]=0;
		}
		int tot=0;
		for(int i=1,j=1;i<=n-1;i++){
			ll now=g[i].z;
			for(;j<=cnt;j++){
				if(!vis[g2[j].id]) continue;
				if(g2[j].z>now) break;
				int f1=_find(g2[j].x),f2=_find(g2[j].y);
				if(f1==f2) continue;
				if(siz[f1]>siz[f2]) swap(f1,f2);
				f[f1]=f2,siz[f2]+=siz[f1],val+=g2[j].z,tot++;
				if(tot==n-1) break;
			}
			if(tot==n-1) break;
			int f1=_find(g[i].x),f2=_find(g[i].y);
			if(f1==f2) continue;
			if(siz[f1]>siz[f2]) swap(f1,f2);
			f[f1]=f2,siz[f2]+=siz[f1],val+=g[i].z,tot++;
			if(tot==n-1) break;
		}
		ans=min(ans,val);
	}
	printf("%lld\n",ans);
	return 0;
}
