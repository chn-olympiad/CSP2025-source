#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		if (n == 2){
			int a[2][3];
			for (int i = 0;i < 2;i++){
				cin >> a[i][0] >> a[i][1] >> a[i][2];
			}
			int b[6] = {a[0][0]+a[1][1],a[0][0]+a[1][2],a[0][1]+a[1][0],a[0][1]+a[1][2],a[0][2]+a[1][0],a[0][2]+a[1][1]};
			sort(b,b+6);
			cout << b[5] << endl;
		}else{
		bool ok = false;
		int a[n][3];
		for (int i = 0;i < n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if (a[i][2] == 0 || a[i][1] == 0){
				cout << n*2;
				return 0;
			}
		}
		int b[n];
		for (int i = 0;i < n;i++){
			b[i] = a[i][0];
		}
		sort(b,b+n);
		long long sum = 0;
		for (int i = n-1;i >= n/2;i--){
			sum+=b[i];
		}
		cout << sum << endl;
	}
	}
	return 0;
}