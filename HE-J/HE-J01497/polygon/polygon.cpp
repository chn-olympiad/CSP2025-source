#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1;i <= n;i ++) cin >> a[i];
	int sum = 0;
	
	int m = -1;
	for (int i = 1;i <= n;i ++){
		if (a[i] > m) m = a[i];
		
		sum += a[i];
	}
	if (sum > m * 2) cout << 1;
	else cout << 0;
	return 0;
}
