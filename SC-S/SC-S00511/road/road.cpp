#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=12;
int n,m,k,fa[N<<1],v[K],ans=2e18,sz[N<<1];
int find(int x){
	return (x==fa[x])?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	if(sz[x]>sz[y])
		swap(x,y);
	fa[x]=y;
	sz[y]+=sz[x];
}
int much,sum;
void init(int now){
	sum=0;
	for(int i=0;i<k;i++){
		if((now>>i)&1){
			sum+=v[i+1];
			much++;
		}
	}
}
struct Edge{
	int u,v,w;
}e[M<<1];
bool cmp(Edge xxx,Edge yyy){
	return xxx.w<yyy.w;
}
bool check(int now,int x){
	return (x<=n)||(now>>(x-n-1)&1);
}
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ttt=clock();
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		v[i]=read();
		for(int j=1;j<=n;j++){
			int x;
			x=read();
			e[++m]={i+n,j,x};
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int l=0;l<(1<<k);l++){
		int num=1;
		init(l);
		if(sum>ans)
			continue;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
			sz[i]=1;
		}
		for(int i=1;i<=m&&num<n+much;i++){
			if(check(l,e[i].u)){
				int fu=find(e[i].u);
				int fv=find(e[i].v);
				if(fu!=fv){
					merge(fu,fv);
//					num++;
					sum+=e[i].w;
					if(sum>=ans)
						break;
				}
			}
		}
//		printf("%lld %lld\n",l,sum);
		ans=min(ans,sum);
		if(clock()-ttt>990){
			printf("%lld\n",ans);
			return 0;
		}
	}
//	printf("%lld\n",clock()-ttt);
	printf("%lld\n",ans);
	return 0;
}