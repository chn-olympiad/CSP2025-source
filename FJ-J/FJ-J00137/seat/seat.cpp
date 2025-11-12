#include <bits/stdc++.h>
using namespace ::std;
int a[105],dp[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int xiaor = a[1];
	sort(a + 1,a + n + 1);
	int k = 1;
	for(int i = 1;i <= n;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= m;j++){
				dp[i][j] = a[k];
				k ++;
			}	
		}else{
			for(int j = m;j >= 1;j++){
				dp[i][j] = a[k];
				k ++;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(dp[i][j] == xiaor){
				cout << j << ' ' << i;
			}
		}
	}
	return 0;
}
