# include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int t;
int n,f,f1;
struct aox{int club1,club2,club3,all;}a[N];
int len1,len2,len3;
int dp[N][N];
bool cmp(aox a,aox b){return a.club1 > b.club1;}
bool cmp1(aox a,aox b){return a.club2> b.club2;}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while(t--){
		f = f1 = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dp[i][j] = 0;
			}
		}
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dp[i][j] = 0;
			}
		}
		for(int i = 1;i <= n;i++){
			cin >> a[i].club1 >> a[i].club2 >> a[i].club3;
			if(a[i].club2 != 0 || a[i].club3 != 0){
				f = 1;
			}
			if(a[i].club3 != 0){
				f1 = 1;
			}
			a[i].all = a[i].club1 + a[i].club2 + a[i].club3;
		}
		if(f == 1 || f1 == 1){
			//背包 
			for(int i = 1;i <= n;i++){//L
				for(int j = 1;j <= n;j++){//物品 
					dp[i][j] = max(dp[i - 1][j] + a[i].club1,
							   max(dp[i - 1][j] + a[i].club2,
							   max(dp[i - 1][j] + a[i].club3,
							   max(dp[i - 1][j - 1] + a[i].club1,
							   max(dp[i - 1][j - 1] + a[i].club2,
							   max(dp[i - 1][j - 1] + a[i].club3,dp[i][j - 1]))))));
				}
			}
			cout << dp[n / 2][n] << endl;
		}else if(f == 0){
			int ans = 0;
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1;i <= n / 2;i++){
				ans = ans + a[i].club1;
			}
			cout << ans << endl;
		}else if(f1 == 0){
			sort(a + 1,a + n + 1,cmp);
			int ans = 0;
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1;i <= n;i++){
				if(a[i].club1 == max(a[i].club1,a[i].club2) && len1 + 1 <= n / 2){
					ans = ans + a[i].club1;
					len1++;
				}
				else {
					ans = ans + a[i].club2;
					len2++;
				}
			}
			int ans1 = 0;
			sort(a + 1,a + n + 1,cmp1);
			for(int i = 1;i <= n;i++){
				if(a[i].club2 == max(a[i].club2,a[i].club1) && len2 + 1 <= n / 2){
					ans = ans + a[i].club2;
					len2++;
				}
				else {
					ans = ans + a[i].club1;
					len1++;
				}
			}
			ans = max(ans,ans1);
			cout << ans << endl;
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}