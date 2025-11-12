#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e4+15,M=2e6+5;
struct node{
	int x,y,c;
	bool operator<(node b){
		return c<b.c;
	}
}a[M];
int w[N],v[15][N];
int fa[N];
int anc(int x){
	if(fa[x]==x)return x;
	return fa[x]=anc(fa[x]);
}
int n,m,k;
vector<pair<int,int>>p;
int num[1<<11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,c;i<=m;++i){
		scanf("%d%d%d",&x,&y,&c);
		a[i]={x,y,c};
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&w[i]);
		for(int j=1;j<=n;++j)
			scanf("%d",&v[i][j]);
	}
	long long ans=1ll<<60;
	sort(a+1,a+m+1);
	for(int u=0;u<1<<k;++u){
		int cnt=m,cu=0;long long s=0;
		for(int i=0;i<k;++i){
			if((u>>i)&1){
				s+=w[i+1];
				++cu;
				for(int j=1;j<=n;++j){
					a[++cnt]={n+i+1,j,v[i+1][j]};
				}
			}
		}
		sort(a+m+1,a+1+cnt);
		for(int i=1;i<=n+k;++i)fa[i]=i;
		for(int i=0,j=m,t=0;;){
			int q=0;
			if(i==m)q=++j;
			else if(j==cnt)q=++i;
			else{
				if(a[i+1].c<=a[j+1].c)q=++i;
				else q=++j;
			}
			int x=a[q].x,y=a[q].y,c=a[q].c;
			if(anc(x)==anc(y))continue;
			fa[anc(x)]=anc(y);
			s+=c;
			if(++t==n+cu-1)break;
		}
		ans=min(ans,s);
	}
	printf("%lld\n",ans);
	return 0;
}
