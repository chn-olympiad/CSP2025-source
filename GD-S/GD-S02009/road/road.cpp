#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,k;
long long fa[200104];
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	return;
}
long long getfa(long long x){
	if(fa[x]!=x)return fa[x]=getfa(fa[x]);
	return x;
}
long long cost[144];

long long ans=1e18;
struct edge{
	long long u,v,val;
	long long town=0;
	edge(){}
	edge(long long uu,long long vv,long long vval,long long ttown){
		u=uu,v=vv,val=vval,town=ttown;
	}
};
edge e[4000004];
long long cnt=0;
bool cmp(edge x,edge y){
	return x.val<y.val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		long long u,v,g;
		scanf("%lld %lld %lld",&u,&v,&g);
		if(u==v)continue;
		e[++cnt]=edge(u,v,g,(long long)0);
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&cost[i]);
		for(long long j=1;j<=n;j++){
			long long val;
			scanf("%lld",&val);
			e[++cnt]=edge(i+n,j,val,i);
		}
	}
	sort(e+1,e+cnt,cmp);
	for(long long i=0;i<(1<<k);i++){
		init();
		long long sum=0;
		long long pt=n-1;
		for(int j=1;j<=k;j++){
			if(i==0)break;
			if((i&(1<<(j-1)))==1){
				sum+=cost[j];
				pt++;
			}
		}
		long long e_cnt=0;
		long long l=1;
		while(l<=cnt){
			if(sum>ans)break;
			if(e[l].town!=0){
				if(i==0){
					l++;
					continue;
				}
				else if((i&(1<<(e[l].town-1)))!=1){
					l++;
					continue;
				}
			}
			long long fx=getfa(e[l].u),fy=getfa(e[l].v);
			if(fx==fy){
				l++;
				continue;
			}
			fa[fy]=fx;
			sum+=e[l].val;
			e_cnt++;
			if(e_cnt>=pt){
				break;
			}
			l++;
		}
		if(sum<ans)ans=sum;
	}
	printf("%lld",ans); 
	return 0;
}
