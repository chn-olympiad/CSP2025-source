#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+5;
const int M=2e6+3e4;
int n,m,k,cnt;
int u,v,w,x;
long long ans;
int fa[N],c[25][N];
struct Node{
	int u,v;
	long long w;
}e1[M];

bool cmp(Node a,Node b){
	return a.w<b.w;
}

int find(int x){
	if(x!=fa[x]){
		return fa[x]=find(fa[x]);
	}
	return x;
}

void Kruskal(int cn){
	sort(e1+1,e1+cn+1,cmp);
	for(int i=1;i<=cn;i++){
		int u = find(e1[i].u);
		int v = find(e1[i].v);
		if(u==v) continue;
		fa[u] = v;
		ans += e1[i].w;
	}
} 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e1[i].u,&e1[i].v,&e1[i].w);
	}
	for(int i=1;i<=n;i++){
		fa[i] = i;
	}
	if(k==0){
		Kruskal(m);
		printf("%lld",ans);
	}else{
		long long result = 0x7f7f7f7f7f7f7f7f;
		for(int i=1;i<=k;i++){
			scanf("%d",&c[i][0]);
			ans = x;
			for(int j=1;j<=n;j++){
				scanf("%d",&c[i][j]);
			}
		}
		for(int i=1;i<=k;i++){
			ans = c[i][0];
			for(int j=1;j<=n;j++){
				e1[m+j].u = n+1;
				e1[m+j].v = j;
				e1[m+j].w = c[i][j];
			}
			Kruskal(m+n);
			result = min(result,ans);
		}
		printf("%lld",result);
	}
	
	return 0;
}
