//t4 polygon
#include<iostream>
#include<algorithm>
#define rf(a, b, c) for(int b = (a); b <= (c); b++)
using namespace std;
int n, m, a[6000];
long long cnt, mod = 998244353;
void solve1(){
	int sum, maxn;
	rf(1, i, (1 << n) - 1){
		sum = 0, maxn = -1;
		m = 0;
		rf(1, j, n) if((i >> (j - 1)) & 1){
			m++;
			sum += a[j];
			maxn = max(maxn, a[j]);
		}
		if(sum > (maxn * 2) && m >= 3) cnt = (cnt + 1) % mod;
	}
	cout << cnt;
}
bool check2(){
	int maxx = -1;
	rf(1, i, n) maxx = max(maxx, a[i]);
	if(maxx <= 1) return true;
	else return false;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	rf(1, i, n) cin >> a[i];
	if(n <= 20) solve1();
	else if(check2()){
		rf(1, i, n) cnt = cnt * 2 % 998244353;
		cout << cnt;
	}
	else cout << 1;
	return 0;
}

