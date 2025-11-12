#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#define pii pair<int,int>
using namespace std;

const int MAXN = 2e2 + 5;
int a[100005][3];
int ans = 0;
int n;
bool vis[MAXN];
vector<pii> vec;
int dp[MAXN][MAXN][MAXN];
void solve(){
	cin >> n;
	bool flag1 = 1,flag2 = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 3;j++)
			cin >> a[i][j];
		flag1 = flag1 && (a[i][1] == 0 && a[i][2] == 0);
	}
	if(flag1){
		vector<int> vec(0);
		for(int i = 1;i <= n;i++) vec.push_back(a[i][0]);
		sort(vec.begin(),vec.end(),greater<int> ());
		int ans = 0;
		for(int i = 0;i < n / 2;i++) ans += vec[i];
		cout << ans << '\n';
		return ;
	}
	int ans = 0;
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;i++)
		for(int j = 0;j <= n / 2;j++)
			for(int k = 0;k <= n / 2 && j + k <= i;k++){
				if(i - j - k > n / 2) continue;
				if(j) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k] + a[i][0]);
				if(k) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1] + a[i][1]);
				if(i - j - k) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k] + a[i][2]);
				if(i == n) ans = max(ans,dp[i][j][k]);
			}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
14230 3941
4732 6608
13198 13925
5356 19920
11299 10796
*/