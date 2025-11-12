#include <bits/stdc++.h>

using namespace std;

int a[105];

int main ()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int q=1; q<=n*m; q++) cin >> a[q];
	int R = a[1];
	
	int cnt=0;
	for (int i=2; i<=n*m; i++){
		if (a[i] > R){
			cnt++;
		}
	}


	cnt++;
	if (cnt*1.0 / m == 0) cout << m;
	else cout << ceil(cnt*1.0 / m);
	
	cout << ' ';
	
	if ( (int)ceil(cnt*1.0 / m) % 2 == 0 ){
		cout << m - cnt%m - 1;
	}else{
		cout << cnt%m;
	}
	
	return 0;
}
