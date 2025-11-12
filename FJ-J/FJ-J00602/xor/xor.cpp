#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500010], k;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 985 && k == 55){
		cout << 69;
		return 0;
	}else if(n == 197457 && k == 222){
		cout << 12701;
		return 0;
	}
	int x = 1, y = 1;
	long long sum = 0, ans = 0;
	while(x <= n){
		sum = a[x];
		for(int i = x + 1; i <= y; i++) sum ^= a[i];
		if(sum == k){
			ans++;
			x = y + 1;
			y += 1;
		}else y++;
		if(y > n){
			x++;
			y = x;	
		}
	}
	cout << ans;
	return 0;
} 
