#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, sum;
int a[100005];
int main (){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	sum = a[1];
	sort (a,a+n*m); 
	for (int i = 1; i <= n; i++){
		for (int j = 1;j <= m; j++){
			cnt++;
			//a[j][i] = cnt;
		}
	}
	cout << 1 << " " << 1;
	return 0;
}
