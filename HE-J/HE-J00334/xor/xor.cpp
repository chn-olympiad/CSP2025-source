// ∆≠∑÷‘§º∆40tps; 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int dp[N][N];
bool st[N];
int n, k, num[N];

bool check(int l, int r){
	for (int i = l; i <= r; i ++){
		if (st[i]) return false;
	}
	return true;
}

int x(int a, int b){

	string stra = "", strb = "", ans = "";
	while (a != 1 && a != 0){
		if (a % 2 == 1) stra = stra + "1";
		else stra = stra + "0"; 
		a /= 2;
	}
	
	
	
	if (a == 1) stra = stra + "1";
	else stra = stra + "0";
	
	
	
	while (b != 1 && b != 0){
		if (b % 2 == 1) strb = strb + "1";
		else strb = strb + "0"; 
		b /= 2;
	}
	

	if (b == 1) strb = strb + "1";
	else strb = strb + "0";
	
	for (int i = 0; i <= min(stra.size(), strb.size()) - 1; i ++){
		if (stra[i] != strb[i]) ans = "1" + ans;
		else ans = "0" + ans;
	}
	
	
	for (int i = 1; i <= int(abs(stra.size() - strb.size())); i ++){
		ans = "1" + ans;
	}
	
	int tp = 1;
	int num = 0;
	for (int i = 0; i <= ans.size() - 1; i ++){
		num += tp * (ans[i] - '0');
		tp *= 2;
	}

	return num;
}

int main(){
	
	// ^ “ÏªÚ∑˚∫≈
	
	freopen("xor.in", "r" , stdin);
	freopen("xoe.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++){
		cin >> num[i]; dp[i][i] = num[i];
	}
	
	for (int i = 1; i <= n; i ++){
		for (int j = i + 1; j <= n; j ++){
			dp[i][j] = x(dp[i][j - 1] , num[j]);
		}
	}
	
	int ansn = 0;
	for (int s = 0; s <= n; s ++){
		for (int i = 1; i <= n - s; i ++){
			if (check(i, i + s) && dp[i][i + s] == k){
				ansn ++;
				for (int j = i; j <= i + s; j ++){
					st[j] = 1;
				}
			}
		}
	}
	
	cout << ansn;
	
	return 0;
}
