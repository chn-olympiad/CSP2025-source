#include<bits/stdc++.h>
using namespace std;
int t,n,cnt;
struct S{
	int x,y,z;
} a[100010];
struct St{
	int cx,cy,cz,sum;
} dp[900010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		cnt = 0;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			cnt += max(a[i].x,max(a[i].y,a[i].z));
		}
		for(int i=1;i<=cnt;i++) dp[i].sum = 1e9,dp[i].cx = dp[i].cy = dp[i].cz = 0;
		for(int i=1;i<=cnt;i++){
			for(int j=n;j>=1;j--){
				if(a[j].x<=i && dp[i-a[j].x].cx<n/2 && dp[i-a[j].x].sum+1<dp[i].sum){
					if(!((i-a[j].x)&&!(dp[i-a[j].x].sum))){
						dp[i].sum = dp[i-a[j].x].sum+1;
						dp[i].cx = dp[i-a[j].x].cx+1;
						dp[i].cy = dp[i-a[j].x].cy;
						dp[i].cz = dp[i-a[j].x].cz;
					}
				}
				if(a[j].y<=i && dp[i-a[j].y].cy<n/2 && dp[i-a[j].y].sum+1<dp[i].sum){
					if(!((i-a[j].y)&&!(dp[i-a[j].y].sum))){
						dp[i].sum = dp[i-a[j].y].sum+1;
						dp[i].cx = dp[i-a[j].y].cx;
						dp[i].cy = dp[i-a[j].y].cy+1;
						dp[i].cz = dp[i-a[j].y].cz;
					}
				}
				if(a[j].z<=i && dp[i-a[j].z].cz<n/2 && dp[i-a[j].z].sum+1<dp[i].sum){
					if(!((i-a[j].z)&&!(dp[i-a[j].z].sum))){
						dp[i].sum = dp[i-a[j].z].sum+1;
						dp[i].cx = dp[i-a[j].z].cx;
						dp[i].cy = dp[i-a[j].z].cy;
						dp[i].cz = dp[i-a[j].z].cz+1;
					}
				}
			}
			if(dp[i].sum == 1e9) dp[i].sum = 0;
		}
		for(int i=cnt;i>=1;i--){
			if(dp[i].sum!=1e9 && dp[i].sum){
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}