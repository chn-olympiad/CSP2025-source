#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e4+5,N=1e6+5,mod=998244353;
ll n,m,k,res=0;
struct node{
	ll u,v,w;
}edges[N+100000];
bool cmp(node a,node b){
	return a.w<b.w;
}
bool t[M];
void kelusikar(){
	for (int i=1;i<=m+k*n;i++){
		if (t[edges[i].u] and t[edges[i].v] or edges[i].v==edges[i].u)continue;
		else{
			res+=edges[i].w;
			t[edges[i].u]=t[edges[i].v]=1;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&edges[i].u,&edges[i].v,&edges[i].w);
	}
	for (int i=1;i<=k;i++){
		ll u,tt;
		scanf("%lld",&u);
		for (int j=1;j<=n;j++){
			scanf("%lld",&tt);
			edges[m+j+(i-1)*n].u=n+i;
			edges[m+j+(i-1)*n].v=j;
			edges[m+j+(i-1)*n].w=tt+u;
		}
	}
	sort(edges+1,edges+1+m+k*n,cmp);
	kelusikar();
	printf("%lld",res);
	return 0;
}


