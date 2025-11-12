#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, lr, arr[maxn];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i++){
		cin >> arr[i];
		if(i == 0)continue;
		if(arr[i] > arr[0])lr++;
	}
	cout << (lr / n + 1) << ' ' << ((lr / n) % 2 == 0 ? (lr % n + 1) : (n - lr % n));
	return 0;
}
