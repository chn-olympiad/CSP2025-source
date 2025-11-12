#include <bits/stdc++.h>
using namespace std;
int a[1000005],sum[5];
int main(){
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;++i){
		cin >> a[i];
	}
	int l = 1;
	int r = n;
	int num = 0;
	int ans = 0;
	for (int i = 1;i <= n;i++){
		r = n;
		while(r >= l){
			num = 0;
			for (int j = l;j <= r;j++){
				num = num^a[j];
			}
			if(num == k && (l > sum[2] || r < sum[1])){
				ans ++;
				sum[1] = l;
				sum[2] = r;
			}
			r--;
		}
		l++;
	}
	cout << ans;
	return 0;
}
