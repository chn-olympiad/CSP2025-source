#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5010],sum[5010];
signed main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n; cin >> n;
	for(int i = 1; i<= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + a[i];
	int final = 0;
	for(int i = 3; i <= n; i++){
		int s = sum[i], ans = 0;
		if(s <= 2*a[i])continue;
		for(int l = 1; l <= i - 1; l++){
			if((s - a[l]) > 2*a[i]){
				ans++;
				s -= a[l];
			}
		}
		int ans1 = 0;
		s = sum[i];
		for(int l = i - 1; l >= 1; l--){
			if((s - a[l]) > 2*a[i]){
				ans++;
				s -= a[l];
			}
		}
		final += max(ans * (ans+1) / 2, ans1 * (ans+1) / 2);
	}
	cout << final;
	return 0;
}
