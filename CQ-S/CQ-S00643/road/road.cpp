#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,m,k,cnt=0,head[N],c[N],sum1=0,sum2=0;
struct edge{
	int to,next,w;
}a[N*2];
void addedge(int u,int v,int w){
	a[++cnt].to=v;
	a[cnt].next=head[u];
	head[v]=u;
	a[cnt].w=w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		sum1+=c[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		sum2+=c[i];
	}
	printf("%lld\n",min(sum1,sum2));
	return 0;
}

