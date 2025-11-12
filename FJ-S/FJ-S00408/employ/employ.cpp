#include<bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m;
string dif;
int pa[N];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	scanf("%s", dif);
	for(int i = 1 ; i <= n ; i ++){
		cin >> pa[i];
	}
	sort(pa + 1, pa + n + 1);
	long long ans = 1, tot = 1;
	int cnt = 0;
	for(int i = n ; i >= 1, cnt <= m; i --){
		ans *= i;
		ans %= mod;
		cnt++;
	}
	for(int i = 1 ; i <= m ; i ++){
		tot *= i;
		tot %= mod;
	}
cout << ans / tot << "\n";
	return 0;
}
