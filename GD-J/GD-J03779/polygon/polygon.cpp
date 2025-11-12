#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long n, a[5005], maxx = -1;
long long jie(int p, int q){
	long long sum = 1;
	for (int i = p;i <= q;i++){
		sum *= i;
	}
	return sum;
}
long long ji(long long x, long long y){
	return jie(x - y + 1, x) / jie(2, y);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxx = max(a[i], maxx);
	}
	if(n == 3){
		if(a[1] + a[2] + a[3] > maxx * 2) cout << 1;
		else cout << 0; 
	}
	if(maxx == 1){
		long long num = 0;
		for(int i = 3;i <= n;i++){
			num += ji(n, i);
		}
		cout << num;
	}
	return 0;
}

