#include<bits/stdc++.h>
using namespace std;

int n , k , num[600000] , dp[200000][200000];
int x_or(int l , int r){
	int he = num[l];
	for(int i = l+1;i <= r;++i){
		he = he^ num[i];
	}
	if(he == k)return 1;
	return 0;
} 
int main(){
	cin >> n >> k;
	for(int i = 1;i <= n;++i){
		cin >> num[i];
	}
	for(int i = 1;i <= n;++i){
		for(int j = i;j <= n;++j){
			if(x_or(i,j) == 1) dp[i][j] = 1;
		}
	}
	int p=0 ,ans = 0;
	for(int i = 1;i <= n;++i){
		for(int j = i;j >p;--j){
			if(dp[j][i] == 1){
				p = i;
				ans++;
			}
		}
	}
	cout << ans ;
	return 0;
}


