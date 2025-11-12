//GZ-S00368 华东师范大学附属贵阳学校 罗翊航
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , t ,a[200005][5] , cnt[5] , dp[200005] , ans;
bool cmp(int a , int b){
	return a > b;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t--){
		memset(a , 0 , sizeof(a));
		memset(dp , 0 , sizeof(dp));
		cin >> n;ll f = n/2;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++){
				cin >> a[i][j];
				if(a[i][j] == 0)cnt[j]++;
			}
		}
		if(cnt[1] == n&&cnt[2]==n){
			int wo[n+5];
			for(int i = 0; i < n; i++){
				wo[i] = a[i][0];
			}
			sort(wo , wo+n,cmp);
			for(int i = 0; i < n/2; i++){
				ans += wo[i];
			}
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
