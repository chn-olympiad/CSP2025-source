#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005],G[12][10005],c[10005],len,plc[12][10005];
long long sol=0,sum=0;
vector<int>g;
struct edge {int u,v,w;}a[2000005],b[50005];
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
void Union(int u,int v,int w,int p,int num) {if(find(u)!=find(v))fa[find(u)]=find(v),sum+=w,(num?g.push_back(num),void():void());}
bool cmp(edge x,edge y) {return x.w<y.w;}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)Union(a[i].u,a[i].v,a[i].w,0,i);
	sol=sum;
	for(int i=1;i<=k&&cin>>c[i];i++)for(int j=1;j<=n;j++)cin>>G[i][j];
	for(int i=1;i<(1<<k);i++) {
		len=0,sum=0;
		for(int j:g)b[++len]=a[j];
		for(int j=1;j<=k+n;j++)fa[j]=j;
		for(int j=1;j<=k;j++)if((1<<j-1)&i)for(int x=1;x<=n;x++)b[++len]={j+n,x,G[j][x]};
		for(int j=1;j<=k;j++)if((1<<j-1)&i)sum+=c[j];
		sort(b+1,b+len+1,cmp);
		for(int j=1;j<=len;j++)Union(b[j].u,b[j].v,b[j].w,0,0);
		sol=min(sol,sum);
	}
	cout<<sol<<endl;
	return 0;
}
