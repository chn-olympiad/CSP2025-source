#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10;
int a[N][5];
struct node{
	int num,cnt;	
}dp[N][5];
int f(int x,int y,int z,int m){
	int ret = max(max(max(x,y),z),m);
	return ret;
}
int id[20];
void solve(){
	memset(dp,0,sizeof(dp));
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= 3;j ++){
			cin >> a[i][j];
		}
	}
	//dp[1][1].num = a[1][1];
	//dp[1][2].num = a[1][2];
	//dp[1][3].num = a[1][3];
	for(int i = 1;i <= n;i ++){
		int c = 0;
		dp[i][0].num = dp[i - 1][0].num;
		dp[i][0].cnt = 0;
		for(int j = 0;j <= 3;j ++){
			dp[i][j].cnt = dp[i - 1][j].cnt;
			dp[i][j].num = dp[i - 1][j].num;
			int id2 = 0;
			for(int k = 0;k <= 3;k ++){
				if(dp[i - 1][j].cnt < n / 2){
					if(dp[i - 1][k].num + a[i][j] > dp[i][j].num){
						dp[i][j].num = dp[i - 1][k].num + a[i][j];
						id2 = j;
					} 
				}
			}	
			
			if(a[i][j] >= dp[i][j].num){
				dp[i][j].num = a[i][j];
				dp[i][j].cnt = 0;
				id2 = j;
			}
			
			id[++ c] = id2;
		}
		for(int j = 1;j <= c;j ++){
			if(id[j]) dp[i][id[j]].cnt ++;
		} 
		//cout << dp[i][0].num << " " << dp[i][1].num << " " << dp[i][2].num << " " << dp[i][3].num << "\n";
		//cout << dp[i][0].cnt << " " << dp[i][1].cnt << " " << dp[i][2].cnt << " " << dp[i][3].cnt << "\n\n";
	}
	cout << f(dp[n][0].num,dp[n][1].num,dp[n][2].num,dp[n][3].num) << "\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T --) solve();
	return 0;
}
