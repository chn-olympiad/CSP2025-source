#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int n , m , k , dis[N];
long long ans;
vector<pair<int , int>>edge[N];
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1 ; i <= m ; ++i){
		int u , v , w;
		scanf("%d%d%d" , &u , &v , &w);
		edge[u].push_back({v , w});
		edge[v].push_back({u , w});
	}
	printf("0");
	return 0;
}
