#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool dp[1005][1005];
	int ab[1005];
	int n,k,a[1005],ans=0;
	memset(ab,0,sizeof(a));
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(a));
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			bool xord = a[i];
			for(int k = i+1;k <= j;k++){
				if(a[i]==xord)xord = 0;
			}
			dp[i][j] = xord;
		}
	}
	int x=1;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(dp[i][j]==k&&i>ab[x]){
				ab[x] = i;
				ans++;
				x++;
			}
		}
	}
	cout << ans;
	return 0;
} 
