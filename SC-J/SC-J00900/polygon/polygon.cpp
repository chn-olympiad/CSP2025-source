#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n, a[5005], s[5005], ans, f, y, x, c;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++ ){
		cin >> a[i];
		c = a[1];
		
		if (a[i] == c) y ++ ;
		if (a[i] != c) f = 1;
	}
	sort(a + 1, a + 1 + n);
	
	if (f == 0){
		for (int i = 2; i <= y; i ++ ){
			x = (y - i + 1) * (y - i) / 2;
			if (x < 0) x = 0;
			
			ans += x;
		}
		
		cout << ans;
		
		return 0;
	}
	
	if (n <= 3){
		if (n == 1){
			cout << 0;
		}
		else if (n == 2){
			cout << 0;
		}
		else{
			if (a[1] + a[2] > a[3]) cout << 1;
			else cout << 0;
		}
		
		return 0;
	}
	
	for (int i = 1; i <= n; i ++ ){
		s[i] = a[i] + s[i - 1];
	}
	
	for (int i = 1; i <= n; i ++ ){
		for (int j = 0; j < i; j ++ ){
			if (s[i - 1] - s[j] > a[i]){
				ans ++ ;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}