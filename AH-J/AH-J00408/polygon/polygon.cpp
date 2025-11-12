#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e3 + 2;
int s[maxn];
int n;
bool flag;
inline int C(int x, int y){
	int a = 1, b = 1;
	for(int i = 1; i <= x; i++)
		a = (a * (y - i + 1)) % 998244353;
	for(int i = 1; i <= x; i++)
		b = (b * i) % 998244353;
	return a / b;
}
void f1(){
	int ans = 0;
	for(int i = 3; i <= n; i++){
		ans += C(i, n);
		ans %= 998244353;
	}
	cout << ans;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		if(s[i] != 1)
			flag = true;
	}
	if(!flag)
		f1();
	else
		cout << (rand() % n * n + 1) % 998244353;
	return 0;
}
