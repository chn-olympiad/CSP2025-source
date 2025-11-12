#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 505;
const int MOD = 998244353;
LL n,m,c[N],a[N],ans;
char s[N];
bool fA;
bool vis[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s + 1;
	for(int i = 1; i <= n; i++){
		if(s[i] == 0) fA = 1;
		cin >> c[i];
	}
	if(fA == 0){
		LL sh = 1;
		LL xi = 1;
		for(int i = n - m + 1; i <= n; i++) sh *= i;
		for(int j = 1; j <= m; j++) xi *= j;
		cout << sh / xi;
	}
	return 0;
}
