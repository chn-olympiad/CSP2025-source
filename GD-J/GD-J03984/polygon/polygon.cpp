#include <iostream>
using namespace std;

int a[5005];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, cnt=0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int ans=0, maxn=0;
	for (int i = 1; i <= n; i++){
		ans += a[i];
		if (a[i] > maxn){
			maxn = a[i];
		}
	}
	if (ans > maxn*2){
		cnt++;
	}
	cout << cnt;
	return 0;
}
