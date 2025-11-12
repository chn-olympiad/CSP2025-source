#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct edge{
	int u,v,w;
}r[1000005];
int n,m,k,f[10005],c[15],a[15][10005];
long long ans;
vector<int>g[10005];
edge e[10005];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){return x^f[x]?f[x]=find(f[x]):x;}
void add(int x,int y){f[find(x)]=find(f[y]);}
int main(){
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;ans+=r[i++].w)scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
	sort(r+1,r+1+n,cmp);
	for(int i=1,j=0;j<n;i++){
		int u=r[i].u,v=r[i].v,w=r[i].w;
		if(find(u)==find(v))continue;
		ans+=w;e[++j]=r[i];
		add(u,v);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}
