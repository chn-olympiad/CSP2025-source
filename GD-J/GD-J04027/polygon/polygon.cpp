#include <bits/stdc++.h>
using namespace std;
int a[5010], b[5010];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon,out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		b[i] = b[i - 1] + a[i];
	}
	int ret = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i + 2; j <= n; j++){
		 int num = b[j] - b[i - 1];
			if (num > a[j] * 2){
				ret++;
				cout << i << ' ' << j << endl;
			}
		}
	}
	cout << ret;
}
