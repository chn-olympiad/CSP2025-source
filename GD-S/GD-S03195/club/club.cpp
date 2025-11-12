#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
namespace Fast{
	inline int fr(){
		int x = 0,f = 1;
		char c = getchar();
		while (c < '0' || c > '9'){
			if (c == '-'){
				f = -1;
			}
			c = getchar();
		}
		while ('0' <= c && c <= '9'){
			x = (x << 1) + (x << 3) + (c ^ 48);
			c = getchar();
		}
		return x * f;
	}
	inline void fw(int x){
		if (x == 0){
			putchar('0');
			return ;
		}
		if (x < 0){
			x = -x;
			putchar('-');
		}
		stack <char> stk;
		while (x){
			stk.push(x % 10 + '0');
			x /= 10;
		}
		while (!stk.empty()){
			putchar(stk.top());
			stk.pop();
		}
	}
	inline void DEBUG(){
		cout<<"CSP-JS rp++; qwq\n";
	}
}

using namespace Fast;
int a[114514][5],dp[205][105][105],b[114514];
void slove(){
	int n = fr();
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= 3;j++){
			a[i][j] = fr();
		}
		b[i] = a[i][1];
	}
	if (n <= 200){
		for (int i = 1;i <= n;i++){
			for (int j = 0;j <= (n >> 1);j++){
				for (int k = 0;k <= (n >> 1);k++){
					int l = i - j - k;
					if (l > (n >> 1) || i < 0 || j < 0 || k < 0 || l < 0){
						continue;
					}
					dp[i][j][k] = 0;
					if (j > 0){
						dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - 1][k] + a[i][1]);
					}
					if (k > 0){
						dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k - 1] + a[i][2]);
					}
					if (l > 0){
						dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k] + a[i][3]);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0;i <= (n >> 1);i++){
			for (int j = 0;j <= (n >> 1);j++){
				ans = max(ans,dp[n][i][j]);
			}
		}
		fw(ans),putchar('\n');
		return ;
	}
	sort(b + 1,b + n + 1);
	int ans = 0;
	for (int i = n;i > (n >> 1);i--){
		ans += b[i];
	}
	fw(ans),putchar('\n');
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = fr();
	while (t--){
		slove();
	}
	return 0;
}
