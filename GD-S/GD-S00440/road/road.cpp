#include<bits/stdc++.h>
using namespace std;
long long fa[10010],n,m,p,ans,biao,c[15],d[15][10010];
long long vis[10010],cnt;
struct aty {
	long long u,v,w;
} a[1000010];
long long dis[1010][1010];
struct bty {
	long long v,w;
	friend bool operator < (bty a,bty b) {
		return a.w>b.w;
	}
};
priority_queue<bty> q;
struct cty{
	long long v,w;
};
vector<cty> E[10010];
long long cmp(aty a,aty b) {
	return a.w<b.w;
}
long long find(long long k) {
	if(fa[k]==k) return k;
	else return fa[k]=find(fa[k]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld%lld",&n,&m,&p);
	if(p==0) {
		for(long long i=1; i<=m; i++) {
			scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		}
		sort(a+1,a+1+m,cmp);
		for(long long i=1; i<=n; i++) fa[i]=i;
		for(long long i=1; i<=m; i++) {
			long long x=find(a[i].u);
			long long y=find(a[i].v);
			if(x!=y) {
				ans+=a[i].w;
				fa[x]=y;
			}
		}
		printf("%lld",ans);
		return 0;
	}

	for(long long i=1; i<=m; i++) {
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		//	E[a[i].u].push_back({a[i].v,a[i].w});
		//	E[a[i].v].push_back({a[i].u,a[i].w});
		dis[a[i].u][a[i].v]=dis[a[i].v][a[i].u]=a[i].w;
	}
	biao=0;
	for(long long i=1; i<=p; i++) {
		scanf("%lld",&c[i]);
		if(c[i]!=0) biao=1;
		for(long long j=1; j<=n; j++) {
			scanf("%lld",&d[i][j]);
			for(long long k=1; k<j; k++) {
				if(d[i][j]+d[i][k]<dis[j][k]) {
					dis[j][k]=dis[k][j]=d[i][j]+d[i][k];
				}
			}
		}

	}
	if(biao==0) {
		
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(dis[i][j]<=2e9){
					E[i].push_back({j,dis[i][j]});
					E[j].push_back({i,dis[i][j]});
				//	cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
				}
			}
		}
		vis[1]=1;
		for(long long i=0;i<E[1].size();i++){
			q.push({E[1][i].v,E[1][i].w});
		}
		cnt=1;
		while(!q.empty()&&cnt<n){
			bty head=q.top();
			q.pop();
			long long u=head.v,w=head.w;
			if(vis[u]) continue;
			vis[u]=1;
			ans+=w;
			cnt++;
			for(long long i=0;i<E[u].size();i++){
				q.push({E[u][i].v,E[u][i].w});
			}
		}
		printf("%lld",ans);
	}else{
		sort(a+1,a+1+m,cmp);
		for(long long i=1; i<=n; i++) fa[i]=i;
		for(long long i=1; i<=m; i++) {
			long long x=find(a[i].u);
			long long y=find(a[i].v);
			if(x!=y) {
				ans+=a[i].w;
				fa[x]=y;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
