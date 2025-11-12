// T4employ
#include <bits/stdc++.h>
using namespace std;
const int maxn = 505,mod = 998244353;
int n,m,c[maxn],num = 0,tot = 0;
unsigned long long ans = 1;
char s[maxn];
int main(){
	freopen('employ.in','r',stdin);
	freopen('employ.out','w',stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		cin >> s[i];
	for(int i = 1;i <= n;i ++)
		cin >> c[i];
	int chose = n;
    for(int i = 1;i <= m;i ++){
    	ans *= chose % mod;
    	chose --;
	}
	cout << ans % mod << "\n";
	return 0;
} 
