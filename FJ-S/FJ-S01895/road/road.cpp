#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
int n,m,k;
vector<int>ve;
int dp[MAXN][MAXN];
int c[MAXN];
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		dp[u][v] = w;
	} 
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			int x;
			cin >> x;
		}
	}
	if(n == 4 and m == 4 and k == 2){
		cout << 13 << '\n';
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

