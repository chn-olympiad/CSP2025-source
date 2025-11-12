#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1622], R, k = 1, l = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	for(int i = 1; i <= n * m; i++){
		if(a[i] == R){
			cout << k << " " << l;
		}
		if(k % 2 == 1)
		l ++;
		else
		l--;
		if(l > m){
			k ++;
			l = m;
		}
		if(l < 1){
			k ++;
			l = 1;
		}
	}
	return 0;
}
