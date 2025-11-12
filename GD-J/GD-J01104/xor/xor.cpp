#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1005], sum[1005];
struct node{
	int l, r;
}qu[100005];
bool cmp(node x,node y){
	return x.r < y.r;
}
struct Node{
	int ans, end;
}dp[1005];
signed main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
	}
	int cnt = 0;
	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			if((sum[r] ^ sum[l-1]) == k){
				qu[++cnt].l = l, qu[cnt].r = r;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = dp[i-1].end; j <= cnt; j++){
			if(qu[j].r == i && qu[j].l >= dp[i-1].end){
				dp[i].ans = dp[i-1].ans + 1;
				dp[i].end = qu[j].r;
				break;
			}
		}
		if(dp[i].ans == 0){
			dp[i].ans = dp[i-1].ans;
			dp[i].end = dp[i-1].end;
		}
	}
	cout << dp[n].ans;
	return 0;
}
