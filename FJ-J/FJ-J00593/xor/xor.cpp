#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int a[N];bool f[N];
int dp[N];int d[N];long long ans2[N];
int e(int x,int y){int cnt,r,d = 1;
	while(x != 0 || y != 0){d *= 2;
		if(x % 2 == y % 2) r += 0;
		else {
			r += d/2;
		}
		x /= 2;y /= 2;
	}
	return r;
}
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	int n,k;cin >> n >> k;long long ans = 0,ans1 = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int r = 1;r <= n;r++){ans1 = 0;
		for(int i = 1;i <= r;i++){
			for(int l = i;l <= r;l++){
				if(e(a[l],a[r]) == k){
			    	l = r;
			    	ans++;
				}
			}
			ans1 = max(ans1,ans);
		}
		ans2[r] = ans1;
	}
	cout << ans2[n];
	return 0;
}