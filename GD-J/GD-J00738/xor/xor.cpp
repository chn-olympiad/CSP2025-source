#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,M = 2e6;
int n,k,a[N],dp[N],t[M],p,d = 0;
bool sum[N][25],mz[25];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i <= 20;i++)
		if( k&(1 << i) ) mz[i] = 1;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = n;i >= 1;i--){
		for(int j = 20;j >= 0;j--){
			sum[i][j] = sum[i+1][j];
			if( a[i]&(1 << j) )
				sum[i][j] = !sum[i][j];
		}
	} 
	t[0] = n+1;
	for(int i = n;i >= 1;i--){
		dp[i] = dp[i+1];
		p = 0,d = 0;
		for(int j = 0;j <= 20;j++){
			if( mz[j] && ( sum[i][j] == 0 ) ) p += (1 << j);
			else if( (mz[j] == 0)&& sum[i][j]) p += (1 << j);
			if( sum[i][j] ) d += (1 << j);
		}
		if( t[ p ] ) dp[i] = max( dp[i], 1 + dp[ t[p] ] );
		t[ d ] = i;
	}
	cout << dp[1];
	return 0;
}
/*
4 0
0 100 100 100
ans : 2
4 100
1 1 1 1
ans : 0
*/
