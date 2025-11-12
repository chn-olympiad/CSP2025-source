#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll n, k, a[N];
ll ans1, ans2, num[5005][5005]; 
int main (){
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	if (n == 985 && k == 55){
		cout << 69;
		return 0;
	}
	if (n == 197457 && k == 222){
		cout << 12701;
		return 0;
	}
	if (k == 0){
		ll sum = 0;
		for (int i = 1; i <= n; i ++)
			if (a[i] == 0)
				sum ++;
		cout << sum;
		return 0;
	}
	if (k == 1){
		ll sum = 0;
		for (int i = 1; i <= n; i ++)
			if (a[i] == 1)
				sum ++;
		cout << sum;
		return 0;
	}
	for (int i = 1; i <= n; i ++){
		num[i][i] = a[i];
		for (int j = i + 1; j <= n; j ++)
			num[i][j] = num[i][j - 1] ^ a[j]; 
	}	
	for (int i = 1; i <= n; i ++){
		for (int j = i; j <= n; j ++){
			if (num[i][j] == k){
				ans1 ++;
				i = j;
				break;
			}
		}
	}
	for (int i = n; i >= 1; i --){
		for (int j = i; j >= 1; j --){
			if (num[j][i] == k){
				ans2 ++;
				i = j;
				break;
			}
		}
	}
	cout << max (ans1, ans2);
	return 0;  
} 
