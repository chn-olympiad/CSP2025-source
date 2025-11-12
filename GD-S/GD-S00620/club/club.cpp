#include <bits/stdc++.h>
using namespace std;

int d[100001][4] = {};
int dp[100001] = {};
int n, ans;

void clubs(){
	for(int j = 1; j <= n; j++) {
		if(d[j][1] >= d[j][2] && d[j][1] >= d[j][3]) dp[j] = 1;
		else if(d[j][2] >= d[j][3]) dp[j] = 2;
		else dp[j] = 3;
	}

	for(int i = 1; i <= 3; i++) {
		int a = 0;
		for(int j = 1; j <= n; j++) if (dp[j] == i) a++;
		if (a > n/2) {
			int temp;
			for(int k = 1; k <= n; k++) if(d[k][i] < d[temp][i]) temp = k;
			d[temp][i] = 0;
			ans = 0;
			clubs();
		}
		else{
			for(int k = 1; k <= n; k++) if (dp[k] == i) ans += d[k][i];
		}
	}
	return;
}

void club(){
	cin >> n;
	for(int i = 1; i <= n; i++) dp[i] = 0;
	for(int j = 1; j <= n; j++) cin >> d[j][1] >> d[j][2] >> d[j][3];
	ans = 0;
	clubs();
	cout << ans << endl;
	return;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)club();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
