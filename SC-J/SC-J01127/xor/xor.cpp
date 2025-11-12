#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;

int n,a[maxn],ans,sum,k;
bool b[maxn];
int dp[maxn][maxn];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
		dp[i][i]=a[i];
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			dp[i][j]=dp[i][j-1]^a[i];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; ++j) {
			if(dp[i][j]==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}