#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, maxx = -1, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ans += a[i];
		maxx = max(maxx, a[i]);
	}
	if(ans > maxx * 2){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
