#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],b[500005];
bool vis[500005];
int dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int l = 0,r = 0;
	dp[0] = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == k && !vis[i]){
			dp[i] = dp[i - 1] + 1;
			vis[i] = 1;
			b[i] = -1;
			r = i;
			for(int j = l;j <= r;j++){
				vis[j] = 1;
			}
			l = 0,r = 0;
		}else if(b[i - 1] == -1 && !vis[i]){
			b[i] = a[i];
			dp[i] = dp[i - 1];
			l = i;
		}else if(b[i - 1] != -1 && !vis[i]){
			b[i] = b[i - 1] xor a[i];
			dp[i] = dp[i - 1];
		}if(b[i] == k && !vis[i]){
			dp[i] = dp[i - 1] + 1;
			r = i;
			for(int j = l;j <= r;j++){
				vis[j] = 1;
			}
			l = 0,r = 0;
		}
	}
	cout << dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
