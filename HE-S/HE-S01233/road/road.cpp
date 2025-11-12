#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

int n,k;
vector <pair <int,pair <int,int> > > E;
int c[20];
bool choose[20];
int fa[10025];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
long long minres=LLONG_MAX;
void dfs(int depth){
	if(depth>k){
		for(int i=1;i<=n+k+1;i++)	fa[i]=i;
		long long res=0;
		for(auto edge:E){
			int length=edge.first;
			int u=edge.second.first,v=edge.second.second;
			if((u-n>0 && !choose[u-n]) || (v-n>0 && !choose[v-n]))	continue;
			if(getfa(u)==getfa(v))	continue;
			res+=length;
			fa[getfa(u)]=fa[getfa(v)];
		}
		for(int i=1;i<=k;i++)
			if(choose[i])	res+=c[i];
		minres=min(minres,res);
		return;
	}
	choose[depth]=1;
	dfs(depth+1);
	choose[depth]=0;
	dfs(depth+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	scanf("%d %d %d",&n,&m,&k);
	while(m--){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		E.push_back({w,{u,v}});
	}
	bool tA=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i])	tA=0;
		bool bh0=0;
		for(int j=1;j<=n;j++){
			int w;
			scanf("%d",&w);
			if(!w)	bh0=1;
			E.push_back({w,{n+i,j}});
		}
		if(!bh0)	tA=0;
	}
	sort(E.begin(),E.end());
	if(tA){
		for(int i=1;i<=n+k+1;i++)	fa[i]=i;
		long long res=0;
		for(auto edge:E){
			int length=edge.first;
			int u=edge.second.first,v=edge.second.second;
			if(getfa(u)==getfa(v))	continue;
			res+=length;
			fa[getfa(u)]=fa[getfa(v)];
		}
		printf("%lld",res);
		return 0;
	}
	dfs(1);
	printf("%lld",minres);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
