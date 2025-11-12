#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1;i <= n-2;i++){
		for (int j = i+2;j <= n;j++){
			int maxa = -1,num=0;
			for (int k = i;k <= j;k++){
				if (a[k] > maxa){
					maxa = a[k];
				}
				num+=a[k];
			}
			if (num > 2 * maxa) {
				ans++;
				for (int l = i;l <= j;l++){
					cout << a[l] << " ";
				}
				cout << endl;
			}
		}
	}
	if (n < 3) cout << 0;
	else cout << ans;
	return 0;
}
