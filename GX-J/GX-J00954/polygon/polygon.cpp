# include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int Mod = 998244353;

int n;
int a[N];
int Max;

int main (){
	
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 0;i < n;i++){
		cin >> a[i];
		Max = max (Max, a[i]);
	}
	
	if (n < 3){
		cout << 0;
		return 0;
	}
	else if (n == 3){
		if (a[0] + a[1] + a[2] > Max * 2){
			cout << 1;
			return 0;
		}
		else {
			cout << 0;
			return 0;
		}
	}
	
	if (Max == 1){
		long long ans = 1;
		
		for (int i = 1;i < n;i++){
			ans *= 2;
			ans %= Mod;
		}
		
		cout << ans - 3;
		return 0;
	}
	
	long long ans = 1;
		
	for (int i = 1;i < n;i++){
		ans *= 2;
		ans %= Mod;
	}
	
	cout << ans - 3;
	
	return 0;
}
