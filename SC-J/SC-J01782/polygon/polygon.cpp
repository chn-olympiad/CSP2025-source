#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, cnt, a[5005], t[5005];
long long ans;
long long C(int a,int b){
	if (a == b) return 1;
	int sum1 = 1, sum2 = 1;
	for (int j = a+1;j <= b;j++) sum1 = sum1*(j%MOD);
	for (int j = 1;j <= (b-a);j++) sum2 = sum2*(j%MOD);
	return (sum1%MOD)/(sum2%MOD)%MOD;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int i = 0;i < n;i++) t[a[i]]++;
	for (int i = 1;i <= 5000;i++)
		if (t[i] >= 1)
			cnt++;
	if (cnt == 1){
		for (int i = 3;i <= n;i++)
			ans = (ans%MOD+C(i,n))%MOD;
		cout << ans;
		return 0;
	}
	sort(a,a+n);
	for (int i = 1;i < (1<<n);i++){
		if (__builtin_popcount(i) <= 2) continue;
		int sum = 0, lst = 0;
		for (int j = 0;j < n;j++){
			if (i&(1<<j)){
				lst = sum;
				sum += a[j];
			}
		}
		if (sum > 2*(sum-lst))
            ans = (ans+1)%MOD;
	}
	cout << ans;
	return 0;
}