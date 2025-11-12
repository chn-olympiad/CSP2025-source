#include <bits/stdc++.h>
using namespace std;
int chu[3][100005];

int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int dp[n+5] = {0};
		int a,b,c;
		for (int i = 1; i <= n ; i++)    cin >> chu[1][i] >> chu[2][i] >> chu[3][i];
		for (int i = 1; i <= n;i++){
			if (a <= n/2){	
				if (chu[1][i] >= chu[2][i] && chu[1][i] >= chu[3][i]){
					dp[i] = chu[1][i] + dp[i-1];
					a++;
				}
				continue;
			}

			if  (b <= n/2){
				if (chu[2][i] >= chu[3][i]){
					dp[i] = chu[2][i] + dp[i-1];
					b++;
				}
				continue;
			}
			if (c <= n/2){
				dp[i] = chu[3][i] + dp[i-1];
				c++;
				continue;
			}
		}
		cout << dp[n] << endl;
	}
	
	return 0;
} 
