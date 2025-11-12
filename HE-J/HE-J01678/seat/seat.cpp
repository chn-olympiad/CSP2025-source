#include <bits/stdc++.h>
using namespace std;
int c[105];
int n, m, ans, x;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int k = n * m;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
	}
	x = c[1];
	sort(c + 1, c + k + 1, greater<int>());
	for(int i = 1; i <= k; i++){
		if(c[i] == x){
			ans = (i - 1) / n + 1;
			cout << ans << " " ;
			if(ans % 2 == 0){
				if(i % n != 0){
					cout << n - (i % n) + 1;
				}else{
					cout << 1;
				}
			}else{
				if(i % n != 0){
					cout << i % n;
				}else{
					cout << n;
				}
			}
		}
	}
	return 0;
}
