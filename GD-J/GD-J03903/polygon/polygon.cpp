//24pts + 24pts
#include<bits/stdc++.h>
//bool Mst;
#define ll long long
using namespace std;
const int N = 5010;
const int M = 998244353;
int n, a[N];
int ans;
int add(int x, int y){
	return (int)((1ll * x + y) % M);
}
int mul(int x, int y){
	return (int)(1ll * x * y % M);
}
void dfs(int k, string s){
	if(k == n){
//		cerr << s << '\n';
		int sum = 0, Max = 0, cnt = 0;
		for(int i = 0; s[i]; ++i){
			if(s[i] == '1'){
				Max = max(Max, a[i + 1]);
				sum += a[i + 1];
				++cnt;
			}
		}
		ans += (cnt >= 3 && sum > 2 * Max);
		ans %= M;
		return ;
	}
	++k;
	dfs(k, s + '0');
	dfs(k, s + '1');
	return ;
}
int c[N];
int power(int x, int y){
	int res = 1;
	while(y){
		if(y & 1) res = mul(res, x);
		x = mul(x, x);
		y >>= 1;
	}
	return res;
}
int C(int x, int y){
//	cerr << "Calc C(" << x << ',' << y << "):\n";
//	cerr << c[y] << ' ' << c[x - y] << '\n';
	y = mul(c[y], c[x - y]);
	y = power(y, M - 2);
	x = c[x];
//	cerr << "Get " << x << " mul " << y << '\n';
	return mul(x, y);
}

//bool Med;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cerr << abs((&Mst)-(&Med)) / 1024.0 / 1024 << "MB" << '\n';
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	if(n <= 10){
		dfs(0, "");
		cout << ans;
		return 0;
	}
	//ÌØÊâĞÔÖÊa_i = 1 
	c[0] = 1;
	for(int i = 1; i <= n; ++i){
		c[i] = mul(c[i - 1], i);
//		cerr << c[i] << ' ';
	}
//	cerr << '\n';
	for(int i = 3; i <= n; ++i){
		ans = add(ans, C(n, i));
//		cerr << C(n, i) << ' ';
	}
	cout << ans;
	
	return 0;
} 
