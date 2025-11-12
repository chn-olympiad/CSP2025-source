#include<bits/stdc++.h>
#define fre(ss,i,j,k) for(int ss=i;ss<=j;ss+=k)
#define rep(ss,i,j,k) for(int ss=i;ss>=j;ss-=k)
using namespace std;
const int N=1e4,M=1e6,K=20;
int n,m,k;
long long c[K],ans=LONG_LONG_MAX;
struct node{int u,v;long long w;}road[M+K*N+5];
bool cmp(node x,node y){return x.w<y.w;}
int fa[N+K+5];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	fre(i,1,m,1)scanf("%d%d%lld",&road[i].u,&road[i].v,&road[i].w);
	fre(i,1,k,1){
		scanf("%lld",&c[i]);
		fre(j,1,n,1){
			int id=m+(i-1)*n+j;
			scanf("%lld",&road[id].w),road[id].u=n+i,road[id].v=j;
		}
	}
	if(n==1){printf(0);return 0;}
	bool fll=1;
	fre(i,1,k,1)if(c[i]!=0)fll=0;
	if(fll){
		sort(road+1,road+m+k*n+1,cmp);
		fre(i,1,n+k,1)fa[i]=i;
		long long bian=0;ans=0;
		fre(i,1,m+k*n,1){
			int u=road[i].u,v=road[i].v,x=find(u),y=find(v);
			long long w=road[i].w;
			if(x!=y){
				bian++,ans+=road[i].w,fa[x]=y;
				if(bian==n+k-1)break;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	sort(road+1,road+m+k*n+1,cmp);
	fre(eq,0,(1<<k)-1,1){
		fre(i,1,n+k,1)fa[i]=i;
		long long ret=0;
		int bian=0,num=0;
		fre(i,1,k,1)if(((eq>>(i-1)))&1)ret+=c[i],num++;
		fre(i,1,m+k*n,1){
			int u=road[i].u,v=road[i].v;
			long long w=road[i].w;
			if(u>n&&!(((eq>>(u-n-1)))&1))continue;
			int x=find(u),y=find(v);
			if(x!=y){
				bian++,ret+=road[i].w,fa[x]=y;
				if(bian==n+num-1)break;
			}
		}
		ans=min(ans,ret);
	}
	printf("%lld",ans);
	return 0;
}