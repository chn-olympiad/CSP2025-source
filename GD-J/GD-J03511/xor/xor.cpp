#include<iostream>
#include<cstring>
#include<stack>
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
int a[5000005],sm[5000005],lst[5000005],mp[5000005],dp[5000005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n = fr(),k = fr();
	memset(mp,0x3f,sizeof(mp));
	mp[0] = 0;
	for (int i = 1;i <= n;i++){
		a[i] = fr();
		sm[i] = (sm[i - 1] ^ a[i]);
		lst[i] = mp[sm[i] ^ k];
		mp[sm[i]] = i;
		//cout<<lst[i]<<' ';
	}
	//cout<<'\n';
	const int maxn = 1e9 + 7;
	for (int i = 1;i <= n;i++){
		dp[i] = dp[i - 1];
		if (lst[i] < maxn){
			if (lst[i] == 0){
				dp[i] = max(dp[i],1LL);
			}
			else{
				dp[i] = max(dp[i],dp[lst[i]] + 1LL);
			}
		}
		//cout<<dp[i]<<' ';
	}
	//cout<<'\n';
	fw(dp[n]);
	return 0;
}
