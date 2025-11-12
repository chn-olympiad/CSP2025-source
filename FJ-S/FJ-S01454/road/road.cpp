#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10,K=11,M=1e6+10,E=1e7;
int n,m,k;
long long dis[N][N],ans;
struct node{
	int u,v;
	long long w;
}e[E];

int c[K],a[K][N],fa[N];

int find(int x){
	if(fa[x]==x)return fa[x];
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fy]=fx;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(dis,LONG_MAX,sizeof dis);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int ui,vi;
		long long wi;
		scanf("%d",&ui);
		scanf("%d",&vi);
		scanf("%d",&wi);
		e[i].u=ui,e[i].v=vi,e[i].w=wi;
		dis[ui][vi]=min(dis[ui][vi],wi);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int x=1;x<=k;x++){
				if(i==j)continue;
				if(dis[i][j]>c[x]+a[x][i]+a[x][j]){
					dis[i][j]=c[x]+a[x][i]+a[x][j];
					m+=1;
					e[m].u=i,e[m].v=j,e[m].w=dis[i][j];		
				}
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1)break;
		int ui=e[i].u,vi=e[i].v,wi=e[i].w;
		if(find(ui)!=find(vi)){
			merge(ui,vi);
			cnt++;
			ans+=wi;
			cout<<ui<<" "<<vi<<" "<<wi<<" ";
		}
	}
	printf("%lld",ans);
	return 0;
}
