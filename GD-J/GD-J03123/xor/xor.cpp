#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, k, cnt;
int a[(int)5e5 + 5];

int main(){
	///*
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	//*/
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	short dp[n];
	memset(dp, -1, sizeof(dp));
	
	for (int i = 0; i <= n; i++){
		for (int j = 0; j < i; j++){
			if (dp[j] == -1) {
				dp[j] = a[i] ^ a[j];
			}else {
				dp[j] = a[i] ^ dp[j];
			}
			
			if (dp[j] == k){
				cnt ++;
				for (int k = 0; k <= j; k++){
					dp[k] = -1;
				}
				break;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
