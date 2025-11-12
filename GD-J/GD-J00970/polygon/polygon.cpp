#include <iostream>
using namespace std;
int a[105];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
//	if(n > 20){
//		puts("0");
//		return 0;
//	}
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < (1 << n); i++){
		int maxx = 0, sum = 0;
		for(int j = 1; j <= n; j++){
			if(!(i & (1 << (j - 1)))) continue;
			maxx = max(maxx, a[j]);
			sum += a[j];
		}
		if(maxx * 2 < sum) ans++;
	}
	cout << ans;
	return 0;
}
