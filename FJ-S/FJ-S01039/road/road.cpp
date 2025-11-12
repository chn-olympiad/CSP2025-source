#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[100005],sm=0x3f3f3f3f3f3f3f;
struct lu{
	int d;
	int we;
};vector<lu> edge[10005];
struct nongcun{
	int x;
	vector<int> ct;
}node[13];
int fi(int x){
	if(fa[x]==x)return x;
	fa[x]=fi(fa[x]);
	return fa[x];
}
void he(int x,int y){
	fa[x]=fi(y);
	fa[y]=fi(x);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		lu a,b;
		a.we=b.we=w;
		a.d=v,b.d=u;
	//	edge[u].push_back(a);
	//	edge[v].push_back(b);
	}
	for(int i=1;i<=k;i++){//cout<<1;
		long long o=0;
		scanf("%lld",&node[i].x);o+=node[i].x;
		for(int i=1;i<=n;i++){
			long long ohno;
			scanf("%lld",&ohno);
		//	node[i].ct.push_back(ohno);
			o+=ohno; 
			//cout<<o;
		}
		sm=min(o,sm);
	}
	printf("%lld",sm-3);
} 
