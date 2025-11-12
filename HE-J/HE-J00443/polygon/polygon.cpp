#include <bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum = 0,max1;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (n == 3){
		for (int i = 1;i <= 3;i++){
			sum += a[i];
		}
		max1 = max(a[3],max(a[1],a[2]));
		if (sum > 2 * max1) cout << 1;
		else cout << 0;
	}
	return 0;
}
