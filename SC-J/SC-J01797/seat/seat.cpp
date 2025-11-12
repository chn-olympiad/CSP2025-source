#include <bits/stdc++.h>
using namespace std;

int a[110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int ans = 1;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
		if (a[i] > a[1]){
			ans++;
		}
	}
	if ((1 + (ans - 1) / n) % 2 == 1){
		cout << 1 + (ans - 1) / n << " " << 1 + (ans - 1) % n << endl;
	}
	else{
		cout << 1 + (ans - 1) / n << " " << n - (ans - 1) % n << endl; 
	}
	return 0;
}