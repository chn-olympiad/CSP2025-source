#include <bits/stdc++.h>
using namespace std;
int n,m,ans,x = 1,y = 1,sum = 1,fx = 0,vis = 0;
int a[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	ans = a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i = 1; i <= n * m; i++) {
		if(a[i] == ans) {
			ans = i;
			break;
		}
	}
//	cout << ans << endl;
	while(sum <= n * m) {
		if(sum == ans) {
			cout << y << " " << x;
			return 0;
		}
//		cout << x << " " << y << endl;
//		cout << sum << endl;
		if(!vis && sum % n == 0) {
			vis = true;
			y++;
			if((sum / n) % 2 == 1) {
				fx = 1;
			} else {
				fx = 0;
			}
		} else {
			vis = false;
			if(fx == 0) {
				x++;
			} else {
				x--;
			}
		}
		sum++;
	}
	return 0;
}
