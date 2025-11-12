#include<bits/stdc++.h>
using namespace std;
const long long nullroad=0x7f7f7f7f7f7f7f7f;
struct awa{
	long long k;
	int st,en;
}p[1000005];
int n,m,k;
int fa[10005];
int l[1005];
vector<awa>d;
long long ans;
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	if(!k){
		for(int i=1;i<=m;i++){
			long long cost;
			int st,en;
			scanf("%d%d%lld",&st,&en,&cost);
			d.push_back({cost,st,en});
		}
		sort(d.begin(),d.end(),[](awa a,awa b){
			return a.k<b.k;
		});
		for(awa v : d){
			int lfa=find(v.st),rfa=find(v.en);
			if(lfa!=rfa)ans+=v.k,fa[rfa]=lfa;
		}
		printf("%lld\n",ans);
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)p[(i-1)*n+j].k=nullroad;
			for(int j=i+1;j<=n;j++){
				p[(i-1)*n+j]={nullroad,i,j};
			}
		}
		for(int i=1;i<=m;i++){
			long long cost;
			int st,en;
			scanf("%d%d%lld",&st,&en,&cost);
			if(st>en)swap(st,en);
			p[(st-1)*n+en].k=min(cost,p[(st-1)*n+en].k);
		}
		for(int i=1;i<=k;i++){
			int ci;
			scanf("%d",&ci);
			memset(l,0,sizeof(l));
			for(int j=1;j<=n;j++){
				scanf("%d",&l[j]);
				for(int k=j-1;k>=1;k--){
					p[(k-1)*n+j].k=min(p[(k-1)*n+j].k,1ll*l[j]+1ll*l[k]+1ll*ci);
				}
			}
		}
		sort(p+1,p+n*n+1,[](awa a,awa b){
			return a.k<b.k;
		});
		int setcnt=0;
		for(int i=1;i<=n*n;i++){
			if(p[i].k==nullroad||setcnt>=n-1)break;
			int lfa=find(p[i].st),rfa=find(p[i].en);
			if(lfa!=rfa)fa[rfa]=lfa,setcnt++,ans+=p[i].k;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
