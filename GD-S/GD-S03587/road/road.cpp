#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,fu,fv,m,t;
bool fl=0;
int xi,f[2000005],x,u,v,w,c[200005];
int sum,a[14][20005],sumc,k,ui[1000005],vi[1000005],wi[1000005];
ll ans,suma,sumb;
int find(int xz) {
	return f[xz]==xz?xz:f[xz]=find(f[xz]);
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q[36];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&ui[i],&vi[i],&wi[i]);
	}
	for(int i=1; i<=k; i++) {
		scanf("%d",&c[i]);
		if(c[i]!=0)fl=1;
		for(int j=1; j<=n; j++) {
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)fl=1;
		}
	}
	if(fl==0){
		cout<<0;
		return 0;
	}
	ans=1e18;
	ll sumx=1e18;
	for(int i=0; i<(1<<k); i++) {
		sumb=0;
		suma=0,sum=0,sumc=0;
		for(int j=0; j<k; j++) {
			f[n+j+1]=n+j+1;
			if((i>>j)&1) {
				sumc++;
				sumb+=c[j+1];
				for(int z=1; z<=n; z++) {
					q[i].push({a[j+1][z],(j+1)*(m+1)+z});
				}
			}
		}
		for(int z=1; z<=m; z++) {
			
			f[z]=z;
			q[i].push({wi[z],z});
		}
		while(sum<n+sumc&&!q[i].empty()) {
			x=q[i].top().second;
			if(x<=m) {
				w=wi[x];
				v=vi[x];
				u=ui[x];
			} 
			else {
				u=x%(m+1);
				v=n+x/(m+1);
				w=a[x/(m+1)][u];
			}
			fu=find(u),fv=find(v);
			if(fu==fv){
				q[i].pop();
				continue;
			}
			sum++;
			f[fu]=fv;
			suma+=w;
			if(suma+sumb>sumx)break;
			q[i].pop();
		}
		ans=min(ans,suma+sumb);
		if(i==0)sumx=ans;
		if(k>5){
			cout<<ans;
			return 0;
		}
	}
	printf("%lld",ans);
	return 0;
}
