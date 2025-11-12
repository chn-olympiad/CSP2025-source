#include<bits/stdc++.h>
using namespace std;

const int N = 500005;
int n, k;
int a[N], dp[N]={0};
int idx=0, cnt=0;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "r", stdout);

	cin >> n >> k;
	cin >> a[1];
	dp[1] = a[1];
	for(int i = 2; i <= n; i++){
		cin >> a[i];
		dp[i] = dp[i-1] ^ a[i];
	}

	for(int i = 0; i < n;){//区间起点
		for(int j = i+1; j <= n; j++){//区间终点 
			if(k == (dp[j] ^ dp[i])){
				i = j;//更改区间起点位置 
				cnt++;
				break;
			}
			if(j == n) i++;
		}
	}

	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
