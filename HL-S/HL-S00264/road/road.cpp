#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
struct Edge{
	int x,y,z,k;
	bool operator <(Edge c) const{
		return z<c.z;
	}
}e[N*200];
int a[20][N],n,m,k,c[N],vis[N],fa[N*2],mii[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
ll solve(){
	ll ans=0;
	for(int j=1;j<=n+k;j++) fa[j]=j;
	for(int i=1;i<m;i++){
		if(vis[e[i].k]) continue;
		if(find(e[i].x)==find(e[i].y)) continue;
		fa[find(e[i].x)]=find(e[i].y);
		ans+=e[i].z;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	}
	int cnt=1;ll C=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);C+=c[i];mii[i]=1e9;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);mii[i]=min(mii[i],a[i][j]);
			e[m+cnt]=Edge{i+n,j,a[i][j],i};
			cnt++;
		}
	}
	m+=cnt;
	sort(e,e+m);
	ll ans=1e18;
	for(int mask=0;mask<(1<<k);mask++){
		for(int i=1;i<=k;i++) vis[i]=0;
		C=0;bool flag=0;
		for(int i=0;i<k;i++){
			if(mask&(1<<i)) C+=c[i+1];
			else{
				vis[i+1]=1;
				if(c[i+1]==0&&mii[i+1]==0){flag=1;break;}
			} 
		}
		if(flag) continue;
		ans=min(ans,solve()+C);
	}
	printf("%lld\n",ans);
	return 0;
} 
