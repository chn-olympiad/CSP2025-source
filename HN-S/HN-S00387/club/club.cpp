#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t,n,ci[N][5],ma;
void dfs(int x,int a,int b,int c,int sum){
	if(x == n+1){
		ma = max(ma,sum);
		return ;
	}
	int sh = n/2;
	if(a < sh)dfs(x + 1,a + 1,b,c,sum + ci[x][1]);
	if(b < sh)dfs(x + 1,a,b + 1,c,sum + ci[x][2]);
	if(c < sh)dfs(x + 1,a,b,c + 1,sum + ci[x][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int top = 0,ans[N]={0};
	while(t--){
		ma = -1;
		cin >> n;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= 3;j ++){
				cin >> ci[i][j];
			}
		}
		dfs(1,0,0,0,0);
		ans[++top] = ma;
	}
	for(int i = 1;i <= top;i ++)cout << ans[i] << "\n";
	return 0;
}
