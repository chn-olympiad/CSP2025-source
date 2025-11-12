#include<iostream>
#include<cstring>
#include<stack>
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
const int mod = 998244353;
int a[5005],sm[5005],c[5005][5005],dp[5005][5005];
signed main(){
	//致敬大预言家 Nad, CSP-J T4 真是数学题 
	//10:32 拿下力 (喜) 
	//文件夹没加 GD- 差点 400->0 
	//猜一手难度 红红黄黄 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n = fr();
	c[1][0] = c[1][1] = 1;
	for (int i = 2;i <= n;i++){
		c[i][0] = 1;
		for (int j = 1;j <= i;j++){
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	for (int i = 1;i <= n;i++){
		a[i] = fr();
	}
	sort(a + 1,a + n + 1);
	int ans = 0;
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++){
		for (int j = 0;j <= a[n];j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i]){
				dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
			}
		}
	}
	for (int i = 1;i <= n;i++){
		sm[i] = sm[i - 1] + a[i];
		if (sm[i - 1] <= a[i] || i <= 2){
			//cout<<"0 ";
			continue;
		}
		//a[x1]+a[x2]+...+a[xk] > a[i] (1<=x1<x2<...<xk<i)
		/*
		for (int j = 1;j < i;j++){
			for (int k = 0;k <= a[i];k++){
				dp[j][k] = 0;
			}
		}
		dp[0][0] = 1;
		for (int j = 1;j < i;j++){
			for (int k = 0;k <= a[i];k++){
				dp[j][k] = dp[j - 1][k];
				if (k >= a[j]){
					dp[j][k] = (dp[j][k] + dp[j - 1][k - a[j]]) % mod;
				}
			}
		}
		*/
		int sum = 0;
		for (int j = 0;j <= a[i];j++){
			sum = (sum + dp[i - 1][j]) % mod;
		}
		int x = lower_bound(a + 1,a + i,a[i] + 1) - a;
		//cout<<x<<' '<<a[x]<<'\n';
		int qwq = i - x;
		//cout<<i<<' '<<a[i]<<' '<<sum<<' '<<qwq<<'\n';
		sum = (sum + qwq) % mod;
		int cnt = 0;
		for (int j = 0;j < i;j++){
			cnt = (cnt + c[i - 1][j]) % mod;
		}
		cnt = ((cnt - sum) % mod + mod) % mod;
		//cout<<"ans["<<i<<"] = "<<cnt<<'\n';
		//cout<<cnt<<' ';
		ans = (ans + cnt) % mod;
	}
	//cout<<'\n';
	fw(ans);
	return 0;
}
