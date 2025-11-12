#include<iostream>
#include<cstring>
#include<stack>
#include<string>
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
int cnt[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n = s.size();
	for (int i = 0;i < n;i++){
		if ('0' <= s[i] && s[i] <= '9'){
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9;i >= 0;i--){
		for (int j = 1;j <= cnt[i];j++){
			fw(i);
		}
	}
	return 0;
}
