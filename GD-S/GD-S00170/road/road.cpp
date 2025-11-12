#include<cstdio>
#include<cstring>

#include<algorithm>

constexpr int maxn=1e4+7;
constexpr int maxm=1e6+7;
constexpr int maxk=10+3;

using i64=long long;

struct{
	int set[maxn+maxk];
	void clr(){memset(set,0xff,sizeof(set));}
	int find(int x){return set[x]<0?x:set[x]=find(set[x]);}
	void unite(int a,int b){
		a=find(a),b=find(b);
		if(a==b) return;
		if(set[a]>set[b]) std::swap(a,b);
		set[b]=a,set[a]--;
	}
}DSU;

//sp A 50pts

struct Edge{
	int a,b,w;
	bool operator<(Edge rhs)const{
		return w<rhs.w;
	}
}E[maxm+maxn*maxk];

int A[maxk][maxn];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int N,M,K;scanf("%d%d%d",&N,&M,&K);
	
	for(int i=0;i<M;i++)
		scanf("%d%d%d",&E[i].a,&E[i].b,&E[i].w);
	
	for(int j=0;j<K;j++){
		scanf("%*d");
		for(int i=1;i<=N;i++)
			scanf("%d",&A[j][i]);
	}
	
	int cur=M;
	for(int j=0;j<K;j++)
		for(int i=1;i<=N;i++)
			if(A[j][i]==0){
				for(int t=1;t<=N;t++){
					if(t==i) continue;
					E[cur++]={i,t,A[j][t]};
				}
				break;
			}
	
	std::sort(E,E+cur);
	
	i64 ans=0;
	DSU.clr();
	for(int i=0;i<cur;i++){
		if(DSU.find(E[i].a)==DSU.find(E[i].b)) continue;
		DSU.unite(E[i].a,E[i].b);
		ans+=E[i].w;
	}
	
	printf("%lld",ans);
	
	return 0;
}
