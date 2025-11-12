#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n, k, a[500005], f = 1, ff = 1, ans, s;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++ ){
		cin >> a[i];
		
		if (a[i] != 1) f = 0;
		if (a[i] != 1 && a[i] != 0) ff = 0;
	}
	
	if (f == 1){
		for (int i = 1; i <= n / 2; i ++ ){
			ans += n / (i * 2);
		}
		
		cout << ans;
		
		return 0;
	}
	if (ff == 1){
		for (int i = 1; i <= n; i ++ ){
			for (int j = i; j <= n; j ++ ){
				s = 0;
				for (int e = i; e <= j; e ++ ){
					s += a[e];
				}
				if (k == 0){
					ans += (s % 2 == 0);
				}
				else{
					ans += (s % 2 == 1);
				}
			}
		}
		
		cout << ans;
		
		return 0;
	}
	
	for (int i = 1; i <= n; i ++ ){
		if (a[i] == k) ans ++ ;
	}
	
	cout << ans;
	
	return 0;
}