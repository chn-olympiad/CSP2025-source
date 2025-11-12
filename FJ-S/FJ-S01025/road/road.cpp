#include<bits/stdc++.h>
#define mk(a,b) make_pair(a,b)
const int _=4e6+100;
using namespace std;
vector<pair<int,int>>e[_];
int n,m,k,c,ans;
//inline void dij(int s,int t){
//	
//}
int main(void){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(mk(v,w));
		e[v].push_back(mk(u,w));
		ans+=w;
	}
	
	for(int i=n+1,w;i<=n+k+1;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			e[i].push_back(mk(j,w));
			e[j].push_back(mk(i,w));
		}
	}
	
//	dij(1,n);
	printf("%d\n",ans);
	return 0;
}
