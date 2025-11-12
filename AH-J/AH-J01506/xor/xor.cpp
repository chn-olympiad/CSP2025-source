#include <iostream>
using namespace std;

int n, k, sum, summ, a[100005], dp[100005];
bool ok=true, flag=true;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(a[i]!=1) ok = false;
		if(a[i]!=1 && a[i]!=0) flag = false;
		if(a[i]==1) sum ++;
		if(a[i]==0) summ ++;
	}
	if(ok) {
		if(k==0) cout<<n/2;
		else if(k==1) cout << n;
		else cout << 0;
	} else if(flag) {
		if(k==0)  {
			int cnt=0;
			int l=0, r=0;
			for(int i=1; i<=n; i++) {
				if(a[i]==1&&a[i-1]==0) l=i;
				if(a[i]==1&&a[i+1]==0) {
					r = i;
					cnt = cnt+(r-l+1)/2;
				}
			}
			cout << summ + cnt;
		} else if(k==1) cout << sum;
		else cout << 0;
	} else {
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			dp[i] = max((dp[i-1]^a[i]), a[i]);
			if(dp[i] == k) {
				dp[i] = 0;
				cnt ++;
			}
		}
		cout << cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
