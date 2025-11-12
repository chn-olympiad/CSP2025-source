#include <bits/stdc++.h>
using namespace std;
const int E=2e6+10,N=1e4+20;
#define int long long
int n,m,k,f[N],c[15],a[15][N];
bool all0=1;
int get(int i){
	if(f[i]==i)return i;
	return f[i]=get(f[i]);
}
void merge(int i,int j){
	f[get(i)]=get(j);
}
struct edge{
	int u,v,w;
}e[E];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int kru(){
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=get(e[i].u),v=get(e[i].v);
		if(u!=v){
			merge(u,v);
			ans+=e[i].w;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	if(k==0){
		printf("%lld",kru());
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0)all0=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]!=0)all0=0;
		}
	}
	if(!all0)printf("%lld",kru());
	else printf("0");
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
