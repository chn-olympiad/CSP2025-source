#include<bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
long long n;
long long a[N]; 
void solve1(){
	int cnt = 0;
	for(int i = 1; i <= (1 << n)-1; i++){
		int t = i;
		long long mx = -1, sum = 0;
		for(int j = n; j >= 1 && t > 0; j--){
			if(t % 2 == 1) sum += a[j], mx = max(mx, a[j]);
			t /= 2;
		}
		if(sum > mx*2) cnt++, cnt %= mod;
	}
	cout << cnt;
	return;
}
void solve2(){
	long long s[N];
	s[0] = 0;
	for(int i = 1; i <= n-2; i++){
		s[i] = s[i-1]*2+(1+i)*i/2;
		s[i] %= mod;
	}
	cout << s[n-2];
} 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 23) solve1();
	else solve2();
	return 0;
}
