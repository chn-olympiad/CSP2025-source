#include<bits/stdc++.h>
using namespace std;
long long n, ans = 0;
int a[5005], b[5005];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		b[i] = b[i-1]+a[i];
	}
	for(int i = 3; i <= n; i++){
		for(int j = 1; j <= n-i+1; j++){
			long long cnt = b[j+i-1]-b[j-1];
			if(cnt > 2*a[j+i-1]){
				ans++;
				ans %= 998;
				ans %= 244;
				ans %= 353;
			}
		}
	}
	cout << ans;
	return 0;
}
