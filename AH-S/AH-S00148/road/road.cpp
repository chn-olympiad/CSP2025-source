#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u,v;
	long long w;
	inline bool operator < (const edge& temp)const{
		return w<temp.w;
	}
};
const int N=1e4+19,K=15;
int n,m,city;
int fa[N];
long long val[K],ec[K][N];
vector<edge>e,ep;
inline int find(int x){
	if(fa[x]==x){
		return fa[x];
	}
	else{
		return fa[x]=find(fa[x]);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&city);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e.push_back((edge){u,v,w});
	}
	for(int i=1;i<=city;i++){
		scanf("%lld",&val[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&ec[i][j]);
		}
	}
	long long ans=1e18,cuttt=0;
	for(int S=0;S<(1<<city);S++){
		long long sum=0,cnt=0,all=n;
		ep=e;
		/*vector<int>exid;
		for(int i=1;i<=n;i++){
			exid.push_back(i);
		}*/
		bool flag=true;
		for(int i=0;i<city;i++){
			if((S>>i)&1){
				sum+=val[i+1];
				all++;
				// exid.push_back(n+i+1);
				for(int j=1;j<=n;j++){
					ep.push_back((edge){n+i+1,j,ec[i+1][j]});
				}
			}
		}
		if(all>n+1){
			continue;
		}
		for(int i=1;i<=all;i++){
			fa[i]=i;
		}
		sort(ep.begin(),ep.end());
		for(auto ex:ep){
			int u=find(ex.u),v=find(ex.v),w=ex.w;
			if(u==v){
				continue;
			}
			fa[u]=v,sum+=w;
			if(++cnt==(all-1)){
				break;
			}
		}
		ans=min(ans,sum);
		if(S==0){
			cuttt=sum;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
