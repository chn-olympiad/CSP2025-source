#include<bits/stdc++.h>
using namespace std;

const int Max = 5e3 + 7;
const int mod = 998244353;
int n, maxx = 0;
int a[Max];
long long ans = 0;

bool cmp(int a, int b){
	return a > b;
}

// l最左侧是第几个元素(即Amax) ok是否已经可行 r最右侧是第几个元素 sum当前和 
void f(int l, int r, int sum, int cnt){
//	cout << "now l, r, sum, cnt = " << l << ", " << r << ", " << sum << ", " << cnt << "\n";
	if (sum > a[l] && cnt >= 3){ // 可行了 
//		cout << "nice >! ans will add " << pow(2, n - r + 1) << "\n";
		ans += pow(2, n - r + 1);
		ans %= mod;
		return;
	}
	if (r > n) return;
	f(l, r + 1, sum + a[r], cnt + 1); // 选上 
	f(l, r + 1, sum, cnt); // 不选 
	
	
}

int xxx(int a, int b){
	int cc = 1;
	for (int i = a; i <= b; i++){
		cc *= i;
		cc %= mod;
	}
//	cout << "i ca~ a * ... * b = " << cc << "\n";
	return cc;
}

int c(int i, int n){
	if (i > n - i) return xxx(i + 1, n) / xxx(1, n - i);
	else return xxx(n - i + 1, n) / xxx(1, i);
}

int pp(int num){
	for (int i = 3; i <= n; i++){
//		cout << "now add c(" << i << ", " << n  << ") = " << c(i, n) << "\n";
		ans += c(i, n);
		ans %= mod;
	}
	return ans;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(a[i], maxx);
	}
	if (maxx == 1){
//		cout << "wwwww!";
		cout << 2 * pp(n) << "\n";
		return 0;
	}
	sort(a + 1, a + n + 1, cmp); // 倒序 
	for (int i = 1; i <= n; i++) f(i, i + 1, 0, 1);
	cout << ans << "\n";
	return 0;
}
