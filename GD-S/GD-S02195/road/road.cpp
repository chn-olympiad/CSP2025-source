#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m,k,ans,a[50][N],c[N];
bool op[N];
struct nb{
	int u,v,w;
}mp[N];
bool nm(nb x,nb y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&mp[i].u,&mp[i].v,&mp[i].w);
	bool po=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0) po=1;
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	if(po) printf("0\n");
	else{
		sort(mp+1,mp+m+1,nm);
		int sum=0;
		for(int i=1;i<=m;i++){
			if(mp[i].u==1&&mp[i].v==1) continue;
			sum++;
			mp[i].u=1,mp[i].v=1;
			ans+=mp[i].w;
			if(sum==n-1) break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

