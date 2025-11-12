#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int MAXN = 100005;
int D[MAXN][3],half_n,N;
long long ans = 0;
struct node {
	long long value;
	int cnt[3];
} dp[MAXN];
void dfs(int x,long long last_score,int a_cnt,int b_cnt,int c_cnt){
	if (a_cnt > half_n || b_cnt > half_n || c_cnt > half_n || x>N+1) return;
	
	dfs(x+1,last_score+D[x][0],a_cnt+1,b_cnt,c_cnt);
	dfs(x+1,last_score+D[x][1],a_cnt,b_cnt+1,c_cnt);
	dfs(x+1,last_score+D[x][2],a_cnt,b_cnt,c_cnt+1);
	
	ans = max(last_score,ans);
}
void solve(){
	cin >> N;
	ans = 0;
	half_n = N/2;
	for (int i=1;i<=N;i++){
		cin >> D[i][0] >> D[i][1] >> D[i][2];
	}
	
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=N;i++){
		for (int j=0;j<3;j++){
			if (dp[i-1].cnt[j] + 1 > half_n) continue;
			
			if (dp[i-1].value + D[i][j] >= dp[i].value){
				dp[i].value = dp[i-1].value + D[i][j];
				ans = max(ans,dp[i].value);
				for(int k=0;k<3;k++){
					dp[i].cnt[k] = dp[i-1].cnt[k];
				}
				dp[i].cnt[j]++;
			}
		}
	}
	
	cout << ans << endl;
}

void solve2(){
	cin >> N;
	ans = 0;
	half_n = N/2;
	for (int i=1;i<=N;i++){
		cin >> D[i][0] >> D[i][1] >> D[i][2];
	}
	
	dfs(1,0,0,0,0);
	
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	cin >> t;
	while(t--){
		solve2();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
