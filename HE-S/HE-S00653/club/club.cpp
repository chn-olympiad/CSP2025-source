#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn][10];
int n;
int ans;
void dfs(int depth, int xcnt, int ycnt, int zcnt, int sum){
	if(xcnt>n/2||ycnt>n/2||zcnt>n/2) return ;
	if(depth==n+1){
		ans=max(ans, sum);
		return ;
	}
	dfs(depth+1, xcnt+1, ycnt, zcnt, sum+a[depth][1]);
	dfs(depth+1, xcnt, ycnt+1, zcnt, sum+a[depth][2]);
	dfs(depth+1, xcnt, ycnt, zcnt+1, sum+a[depth][3]); 
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >>t;
	while(t--){
		cin >>n;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=3; ++j){
				cin >>a[i][j];
			}
		}
		ans=0;
		dfs(1, 0, 0, 0, 0);
		cout <<ans <<"\n";
	}
	return 0;
} 
