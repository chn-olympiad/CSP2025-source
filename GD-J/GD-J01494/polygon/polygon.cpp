#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[5005], sum, num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n < 3){
		cout << 0;
		return 0;
	} 
	sort(a + 1, a + n + 1);
	if (n == 3){
		if (a[1] + a[2] > a[3]){
			cout << 1;
		}
		else{
			cout << 0;
		}
		return 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = i + 2; j <= n; j++){
			sum = 0;
			for (int k = i; k <= j; k++){
				sum += a[k];
			}
			if (a[j] * 2 < sum){
				num++;
			}
		}
	}
	cout << num;
	return 0;
} 
