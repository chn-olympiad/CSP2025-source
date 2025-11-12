#include<bits/stdc++.h>
#define N 207
#define M 100007
#define ll long long
using namespace std;
int T, n;
int a[M][4];
ll dp[N][N][N];
struct Node{
	int v, p;
	bool operator <(const Node no)const{
		return v < no.v;
	}
};
Node b[M];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		memset(dp, 0, sizeof dp);
		cin >> n;
		bool fl = 1;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][3] != 0)fl = 0;
		}
		if(fl){
			ll sum = 0;
			for(int i = 1;i <= n;i++){
				sum += a[i][1];
				b[i].v = a[i][2] - a[i][1];
				b[i].p = i;
			}
			sort(b + 1, b + 1 + n);
			for(int i = n;i > n / 2;i--){
				sum += b[i].v;
			}
			cout << sum << '\n';
			continue;
		}
		ll ans = 0;
		dp[1][1][0] = a[1][1];
		dp[1][0][1] = a[1][2];
		dp[1][0][0] = a[1][3];
		for(int i = 2;i <= n;i++){
			for(int A = 0;A <= i && A <= n / 2;A++){
				for(int B = 0;B <= i - A && B <= n / 2;B++){
					int C = i - A - B;
					if(C > n / 2)continue;
					if(C > 0)dp[i][A][B] = dp[i - 1][A][B] + a[i][3];
					if(A > 0)dp[i][A][B] = max(dp[i][A][B], dp[i - 1][A - 1][B] + a[i][1]);
					if(B > 0)dp[i][A][B] = max(dp[i][A][B], dp[i - 1][A][B - 1] + a[i][2]);
					if(i == n)ans = max(ans, dp[i][A][B]);
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
