#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int p[N][10];
int dp[2][N][N];
int ans[N];
int po[10];
int checkk[10];

bool check_p(){
	for(int i = 0;i < 8;i ++){
		if(po[i] != checkk[i]) return 0;
	}
	return 1;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	int ktm = 0;
	while(k){
		po[ktm] = k % 2;
		k /= 2;
		ktm ++;
	}
	for(int i = 1;i <= n;i ++){
		int x;
		cin >> x;
		vector<int> bIT;
		while(x){
			bIT.push_back(x % 2);
			x /= 2;
		}
		for(int j = 0;j < bIT.size();j ++){
			p[i][j] = bIT[j];
		}
		for(int j = 0;j < 8;j ++){
			p[i][j] += p[i - 1][j];
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 0;j < i;j ++){
			for(int k = 0;k < 8;k ++) checkk[k] = (p[i][k] - p[j][k]) % 2;
			if(check_p()){
				dp[1][i][j] = max(dp[1][i][j],ans[j] + 1);
			}
			dp[0][i][j] = max(dp[0][i][j],ans[j]);
			ans[i] = max(ans[i],max(dp[1][i][j],dp[0][i][j]));
		}
	}
	int mans = 0;
	for(int i = 1;i <= n;i ++){
		mans = max(mans,ans[i]);
	}
	cout << mans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
