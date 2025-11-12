#include<iostream>
#include<algorithm>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int n,k,a[N],dp[N],maxn[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int x = 0;
		for(int j = i;j >= 1;j--){
			x ^= a[j];
			if(x == k){
				dp[i] = maxn[j - 1] + 1;
				break;
			}
		}
		maxn[i] = max(maxn[i - 1],dp[i]);
	}
	cout << maxn[n];
	return 0;
}
