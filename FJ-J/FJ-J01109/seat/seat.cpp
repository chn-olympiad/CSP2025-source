#include <bits/stdc++.h>
using namespace std;
int a[105],ans = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2;i <= n * m;i ++){
		cin >> a[i];
		if (a[i] > a[1]){
			ans ++;
		}
	}
	int an,am;
	an = ceil(1.0 * ans / n);
	am = ans % n;
	if (am == 0){
		am = n;
	}
	if (an % 2 == 1){
		cout << an << " " << am;
	}
	else {
		cout << an << " " << n - am + 1;
	}
	return 0;
}

