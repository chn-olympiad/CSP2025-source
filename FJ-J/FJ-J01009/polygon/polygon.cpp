#include <cstdio>
#include <algorithm>
using namespace std;
const int mo = 998244353;
int a[5005],dp[5005][5005],t[5005][5005],b[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans = 0;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= a[i];j++) {
			t[i][j] = t[i-1][j];
		}
		for (int j = a[i]+1;j <= 5000;j++) {
			if (j == 2*a[i]) {
				t[i][j] = (mo+t[i-1][j]+b[j-a[i]]-1)%mo;
			}
			else {
				t[i][j] = (t[i-1][j]+b[j-a[i]])%mo;
			}
		}
		t[i][5001] = t[i-1][5001];
		for (int j = 5001-a[i];j <= 5000;j++) {
			t[i][5001] = (t[i][5001]+b[j])%mo;
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= a[i];j++) {
			dp[i][j] = dp[i-1][j]%mo;
		}
		for (int j = a[i]+1;j <= 5000;j++) {
			dp[i][j] = ((dp[i-1][j]+dp[i-1][j-a[i]])%mo+t[i-1][j-a[i]])%mo;
		}
		dp[i][5001] = (dp[i-1][5001]+t[i-1][5001])%mo;
		for (int j = 5001-a[i];j <= 5000;j++) {
			dp[i][5001] = ((dp[i][5001]+dp[i-1][j])%mo+t[i-1][j])%mo;
		}
	}
	for (int i = 1;i <= 5001;i++) {
		ans = (ans + dp[n][i])%mo; 
	}
	printf("%d",ans);
	return 0;
}
