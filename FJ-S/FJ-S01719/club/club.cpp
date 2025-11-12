#include<bits/stdc++.h>
using namespace std;
int N = 1e+10;
int t = 0;
int main(){
	freopen('club.in','r',stdin)
	freopen('cluo.out','w',stdout)
	int dp[N][N], n, ans, a[N], nMostmumber;
	cin >> t;
	for(int k = 1;k <= t;t++){
		cin >> n;
		nMostmumber = n / 2;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
			cin >> dp[i][j];
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
			a[i] + dp[i][j];
			}
		}
		cout << a[1] << endl;
	}
	return 0;
} 
