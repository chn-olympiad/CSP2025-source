#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

int t,n;
int a[N][5];
int flag[5];
int ans,idx;
int dp[N];

bool cmp(int x,int y){
	return x < y;
}

void init(){
	for (int i=1;i<=n;++i) a[i][1] = a[i][2] = a[i][3] = 0;
	flag[1] = flag[2] = flag[3] = 0;
	for (int i=1;i<=n;++i) dp[i] = 0;
	ans = idx = 0;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	cin >> t;
 	while (t--){
 		cin >> n;
 		
 		init();
 		
 		for (int i=1;i<=n;++i){
 			cin >> a[i][1] >> a[i][2] >> a[i][3];
 			if (a[i][1] >= max(a[i][2],a[i][3])){
 				flag[1]++;
				ans += a[i][1];	
 			}
 			
 			else if (a[i][2] >= max(a[i][1],a[i][3])){
 				flag[2]++;
				ans += a[i][2];	
 			}
 			
 			else if (a[i][3] >= max(a[i][1],a[i][2])){
 				flag[3]++;
				ans += a[i][3];	
 			}
		 }
	
		 int p = 0;
		 if (flag[1] > n/2) p = 1;
		 if (flag[2] > n/2) p = 2;
		 if (flag[3] > n/2) p = 3;
		 
		 if (p == 0){
		 	cout << ans << '\n';
		 	continue;
		 }
		 
		 for (int i=1;i<=n;++i){
		 	if (p == 1 && a[i][1] >= max(a[i][2],a[i][3])) dp[++idx] = a[i][1] - max(a[i][2],a[i][3]);
 			else if (p == 2 && a[i][2] >= max(a[i][1],a[i][3])) dp[++idx] = a[i][2] - max(a[i][1],a[i][3]);
 			else if (p == 3 && a[i][3] >= max(a[i][1],a[i][2])) dp[++idx] = a[i][3] - max(a[i][2],a[i][1]);
		 }
		 
		 sort(dp+1,dp+1+idx,cmp);
		 for (int i=1;i<=idx-n/2;++i) ans -= dp[i];
		 cout << ans << '\n';
	 }
 	
 	
 	
 	
 	
 	
 	return 0;
 }
