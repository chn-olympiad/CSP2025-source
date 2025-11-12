#include<bits/stdc++.h>
using namespace std;
int n, t, a[100005][4];
int ma[100005][1], md[100005][4], ans;
int c[4] = {}, mij[3];
int s[4];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while(t -- ){
		ans = 0;
		scanf("%d", &n );int maxi = n / 2;
		for(int i = 1;i <= n;i ++ ){
			ma[i][1] = 0;
		}
		
		for(int i = 1;i <= n;i ++ ){
			for(int j = 1;j <= 3;j ++ ){
				scanf("%d ", &a[i][j]);
				ma[i][1] = max(ma[i][1], a[i][j]);
				if(ma[i][1] < a[i][j]){
					ma[i][0] = j;
				}
				md[i][1] = ma[i][1] - min(md[i][1], a[i][j]);
				if(md[i][1] > ma[i][j]){
					md[i][0] = j;
				}
			}
		}
		for(int i = 1;i <= n;i ++ ){
			ans += ma[i][1];
			c[ma[i][0]]++;
		}
		for(int i = 1;i <= n;i ++ ){
			for(int j = 1;j <= 3;j ++ ){

			if(c[j] > maxi){
				for(int i = 1;i <= n;i ++ ){
					if(ma[i][0] == j){
						mij[j] = min(mij[j], ma[i][1]);
						s[j] = i;
					}
				}
				c[j] --;
				ans -= mij[j];
				
				ans += md[s[j]][1];
		    }
		
	}}cout << ans << endl;
	
}return 0;
}
