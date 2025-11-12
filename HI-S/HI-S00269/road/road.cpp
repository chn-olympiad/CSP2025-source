#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
struct edge{
	int y,m,_new;
};
bool cmp(edge a,edge b){
	return a.m < b.m;
}
int a[MAX],ans=0;
vector <edge> G[MAX];
int coin[11];
bool used[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,num;
	scanf("%d%d%d",&n,&m,&num);
	for(int i = 1;i <= m;i++){
		int x,y,u;
		scanf("%d%d%d",&x,&y,&u);
		G[x].push_back({y,u,0});
		G[y].push_back({x,u,0});
	}
	for(int i = 1;i <= num;i++){
		memset(a,0,sizeof(a));
		scanf("%d",&coin[i]);
		for(int j = 1;j <= n;j++){
			scanf("%d",&a[j]);
		}
		for(int k = 1;k < n;k++){
			for(int l = k + 1;l <= n;l++){
				G[k].push_back({l,a[k]+a[l],i});
				G[l].push_back({k,a[k]+a[l],i});
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(G[i].size()>0){
			sort(G[i].begin(),G[i].end(),cmp);
			if(G[i][0]._new > 0){
				if(used[G[i][0]._new] == 0)ans += coin[G[i][0]._new];
				used[G[i][0]._new] = 1;
			}
			ans += G[i][0].m;
		}
	}
	printf("%d",ans);
	return 0;
} 
