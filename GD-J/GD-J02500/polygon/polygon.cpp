#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int n, a[5005], sum[5005];
long long d[5005][5005];
long long ans, summ;
long long f(int step, int cnt){
	//if (d[step][cnt]!=-1) return d[step][cnt];
	if (step==0){
		if (cnt>0) return 0;
		else {
			return 1;
		}
	}
	if (sum[step]<cnt){
		d[step][cnt] = 0;
		return 0;
	}
	return f(step-1, cnt) + f(step-1, cnt-a[step]);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++) sum[i] = sum[i-1]+a[i];
	for (int i=3; i<=n; i++){
		ans = (ans+f(i-1, a[i]+1)%MOD)%MOD;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
