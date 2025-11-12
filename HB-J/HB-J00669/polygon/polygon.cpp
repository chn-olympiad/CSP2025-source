#include <bits/stdc++.h>
using namespace std;
int ans,n,a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i ++) cin >> a[i];
	for(int i = 0;i < n-3;i ++){
		int sum = 0,max = -1;
		for(int j = i;j < n;j ++){
			sum += a[j];
			if(max < a[j]) max = a[j];
			if(sum > 2*max) ans++;
		}
	}
	cout << ans%998244353;
	return 0;
}
