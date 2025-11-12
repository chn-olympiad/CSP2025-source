#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
long long sum[5005] = {};

int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 3;i <= n;i++){
		for(int j = 1;j <= n;j++){
			long long maxll = 0;
			for(int k = j;k <= j + i;k++){
				if(maxll < sum[k]){
					maxll = sum[k];
				}
			}
			if(sum[j + i] - sum[j - 1] > maxll * 2){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
