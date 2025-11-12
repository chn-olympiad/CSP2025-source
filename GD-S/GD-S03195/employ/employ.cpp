#include<iostream>
#include<stack>
#include<cstring>
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
int n,m,ans,a[505];
bool f[505],vis[505];
void dfs(int cur,int sum,int cnt){
	//cout<<cur<<' '<<sum<<' '<<cnt<<' '<<(n - cur + 1) + sum<<'\n';
	if (cur > n){
		ans = (ans + (sum >= m)) % mod;
		return ;
	}
	for (int i = 1;i <= n;i++){
		if (vis[i]){
			continue;
		}
		vis[i] = true;
		dfs(cur + 1,sum + (f[cur] && cnt < a[i]),cnt + (!f[cur]));
		vis[i] = false;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = fr(),m = fr();
	string s;
	cin>>s;
	for (int i = 0;i < n;i++){
		f[i + 1] = (s[i] - '0');
	}
	for (int i = 1;i <= n;i++){
		a[i] = fr();
	}
	if (n <= 10){
		dfs(1,0,0);
		fw(ans);
		return 0;
	}
	return 0;
}
