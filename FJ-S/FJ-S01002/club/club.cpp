//玄学dp这一块
//dp[i][j]表示当第i项取j种时每个人的情况
//dp[i][j] = max(dp[i - 1][1 ~ 3].num ......)
//开始调吧 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
struct node{
	int num,d[4];
}dp[N][5];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%d",&n); 
		//输入
		for(int i = 1;i <= n;i++){
			int tmp[4];scanf("%d%d%d",&tmp[1],&tmp[2],&tmp[3]);
			for(int j = 1;j <= 3;j++){
				int max_id = 0;
				for(int k = 1;k <= 3;k++){
					if(dp[i - 1][k].d[j] < n / 2 && dp[i - 1][k].num > dp[i - 1][max_id].num){
						max_id = k;
						//cout << k << '\n';
					}
					//cout << dp[i - 1][k].num << '\n';
				}
				if(max_id == 0 && !(dp[i - 1][1].num == 0 && dp[i - 1][2].num == 0 && dp[i - 1][3].num == 0)) dp[i][j].num = 0;
				else {
					dp[i][j].num = dp[i - 1][max_id].num + tmp[j];
					
				}
				for(int k = 1;k <= 3;k++) dp[i][j].d[k] = dp[i - 1][max_id].d[k];
				dp[i][j].d[j] = dp[i - 1][max_id].d[j] + 1;
			}
		}
		for(int j = 1;j <= 3;j++){
			for(int i = 1;i <= n;i++){
				printf("%d,%d,%d,%d ",dp[i][j].d[1],dp[i][j].d[2],dp[i][j].d[3],dp[i][j].num);
			}
			printf("\n");
		}
		
		printf("%d\n",max(dp[n][1].num,max(dp[n][2].num,dp[n][3].num))); 
	}
	
	
	return 0;
}

