#include<cstdio>
#include<algorithm>
#define int long long
const int maxn=1e6+5;
const int maxm=2e6+5;
using namespace std;
int n,m,k,u,v,w,len,cnt,ans;
int father[maxm],b[maxn];
struct edge{
	int u,v,w;
	bool operator < (const edge&A) const{
		return w<A.w;
	}
}a[maxm];
int find(int x){
	if(x==father[x]){
		return father[x];
	}
	return father[x]=find(father[x]);
}
void merge(int x,int y){
	int a=find(x),b=find(y);
	father[a]=b;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
		father[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		a[++len]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&w);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w);
			a[++len]={n+i,j,w};
		}
	}
	sort(a+1,a+len+1);
	for(int i=1;i<=len;i++){
		if(find(a[i].u)!=find(a[i].v)){
			ans+=a[i].w;
			merge(a[i].u,a[i].v);
		}
	}
	printf("%lld",ans);
	return 0;
}
