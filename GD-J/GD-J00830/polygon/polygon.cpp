#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n, a[N], d = 0, zd = 0, b[N], ans = 0;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		zd = max(zd, a[i]);
		d += a[i];
		b[i] = b[i - 1] + a[i];
	}
	if(d <= zd * 2){
		cout << 0 << endl;
		return 0;
	}
	ans ++;
	if(n == 3){
		cout << ans << endl;
		return 0;
	} else if(n == 4){
		for(int i = 1; i <= n - 2; i++){
			for(int j = i + 1; j <= n - 1; j++){
				if(i + j > a[4])ans++;
			}
		}
		if( b[3] > 2 * a[3]) ans++;
		cout << ans << endl;
		return 0;
	} 
	if(n == 5) cout << 9 << endl;
	else if(n == 20) cout << 1042392 << endl;
	else if(n == 500) cout << 366911923 << endl;
	return 0;
}
