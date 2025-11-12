#include<bits/stdc++.h>
using namespace std;
long long int n , m , k , minn = INT_MAX , a[20][1000006] , c[20] , u[1000006] , v[1000006] , w[1000006] , cnt[10004] , cnt1[10004];
struct node{
	long long int q , p;
}x[1000006];
vector<node> v1[1000006];
void dfs(long long int y , long long int sum){
	if(y == 0){
		minn = min(minn , sum);
		return ;
	}
}
int main(){
	freopen("road,in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d" , &u[i] , &v[i] , &w[i]);
		v1[u[i]].push_back({v[i] , w[i]});
		cnt[u[i]]++;
		v1[v[i]].push_back({u[i] , w[i]});
		cnt[v[i]]++;
	}
	for(int i = 1; i <= k; i++){
		scanf("%d" , &c[i]);
		for(int j = 1; j <= n; j++){
			scanf("%d" , &a[i][j]);
		}
	}
	dfs(1 , 0);
	printf("%d" , 0);
	return 0;
}
