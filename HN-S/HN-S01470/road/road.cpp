#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int N=1e4+5;
int n,m,k;
struct Edge{ int v,w;};
vector<Edge> e[N];
void DJ(int x,int y){
	priority_queue<pair<int,int> > q;
	q.push({x,y});
	while(!q.empty()){
		auto it=q.top();
		q.pop();
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	}
	for(int i=2;i<=n;i++){
		DJ(1,i);
	}
	return 0;
}
/*全源最短路
#只拿特殊性质A的分#
1.直接把乡镇改造的道路同样放进图中
2.取1号，对其求全源最短路 
BUT:I don't know how to do!忘记了666 
*/
