#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int P = 998244353;
int n,a[N],ans=0,dp[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		dp[i] = dp[i-1]+a[i];
	}
	sort(a,a+n+1);
	if(n == 3){
		if(a[1]+a[2] > a[3])
			cout << 1;
		else cout << 0;
		return 0;
	}
	for(int i=3;i<=n;++i){//±éÀú±ßÊý 
		for(int j=1;j<=n-i+1;++j){
			if(dp[i+j-1]-dp[j-1] > 2*a[i+j-1]){
				++ans;
				for(int k=j+1;k<i+j;++k){
					if(dp[i+j]-dp[j-1]-a[k] > 2*a[i+j]){
						++ans;
					}
				}
			}
		}
	}
	cout << ans%P;
	return 0; 
}
