#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int n,m,k;
vector<pii> g[10050];
//priority_queue<pii> g[1050];
//int g[1030][1030];
int aj[10050];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[a].push_back({b,c});
		g[b].push_back({a,c});
		//g[a][b]=g[b][a]=c;
	}
	for (int r=1;r<=k;r++){
		int c=0;
		scanf("%d",&c);
		for (int i=1;i<=n;i++)
		scanf("%d",&aj[i]);
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				g[i].push_back({j,c+aj[i]+aj[j]});
				g[j].push_back({i,c+aj[i]+aj[j]});
			}
		}
	}
	
	return 0;
}
