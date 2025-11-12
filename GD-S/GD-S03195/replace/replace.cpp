#include<iostream>
#include<stack>
#include<cstring>
#include<map>
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
int mod[10] = {0,13331,998244353,10000007};
map <int,int> mp[10];
int h[5000005][5],sms[5000005][5],smt[5000005][5],diff[5000005];
bool f[5000005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n = fr(),q = fr();
	for (int i = 1;i <= n;i++){
		string s,t;
		cin>>s>>t;
		int ssiz = s.size();
		for (int k = 1;k <= 3;k++){
			int hs = 0,ht = 0;
			for (int j = 0;j < ssiz;j++){
				hs = ((hs * 7LL) % mod[k] + (s[j] - 'a' + 1)) % mod[k];
				ht = ((ht * 7LL) % mod[k] + (t[j] - 'a' + 1)) % mod[k];
			}
			int x = ((ht - hs) % mod[k] + mod[k]) % mod[k];
			mp[k][x]++;
		}
	}
	for (int i = 1;i <= q;i++){
		string s,t;
		cin>>s>>t;
		int ssiz = s.size(),tsiz = t.size();
		if (ssiz != tsiz){
			cout<<"0\n";
			continue;
		}
		for (int j = 0;j < ssiz;j++){
			f[j] = false;
			diff[j] = 0;
		}
		for (int k = 1;k <= 3;k++){
			sms[0][k] = smt[0][k] = 0;
			for (int j = 0;j < ssiz;j++){
				sms[j][k] = ((sms[j - 1][k] * 7LL) % mod[k] + (s[j] - 'a' + 1)) % mod[k];
				smt[j][k] = ((smt[j - 1][k] * 7LL) % mod[k] + (t[j] - 'a' + 1)) % mod[k];
			}
			for (int j = ssiz - 1;j >= 0;j--){
				if (f[j]){
					continue;
				}
				int d = ((smt[j][k] - sms[j][k]) % mod[k] + mod[k]) % mod[k];
				int x = mp[k][d];
				if ((k > 1 && x != diff[j]) || x == 0){
					f[j] = true;
					break;
				}
				diff[j] = x;
				if (s[j] != t[j]){
					break;
				}
			}
		}
		int sum = 0;
		for (int j = 0;j < ssiz;j++){
			if (!f[j] && diff[j] > 0){
				sum = diff[j];
				break;
			}
		}
		fw(sum),putchar('\n');
	}
	return 0;
}
