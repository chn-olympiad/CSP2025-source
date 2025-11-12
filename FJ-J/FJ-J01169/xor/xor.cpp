#include<bits/stdc++.h>
using namespace std;
int a[1005], n, ans = 0;
bool k;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n;
	cin >> k;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i];
		if(a[i] - n <= k)
			ans += k;	
		}
	}
		ans--;
	cout << ans;		
	return 0;
}
