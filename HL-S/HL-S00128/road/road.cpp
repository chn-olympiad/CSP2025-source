#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
int n,m,k;
struct test{
	int to;int m;int num;
};
vector<test> q[N];
bool v[N];
/*void dfs(int u){
	for(int i = 1;i <= q[u].size();i++){
		if(v[q[u].num]==1){
			continue;
		}
	}
}*/
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i = 1;i <= n;i++){
		int u,v,w;
		cin >>u>>v>>w;
		q[u].push_back({v,w,i});
		q[v].push_back({u,w,i});
		ans+=w;
	}
//	dfs(1);
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n+1;j++){
			int a;cin >>a;
		}
	}
	cout <<ans;
	return 0;
}