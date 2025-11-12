#include <bits/stdc++.h>
using namespace std;
int t,n,p;
int a[100010][5];
int dp[100005][5][35];
int sum[100005];
int cnt1,cnt2,cha1[100005],cha2[100005];
bool cmp(int x,int y){
	return x<y;
}
int maxn;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		maxn=0;
		memset(dp,0,sizeof(dp));
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j];
			}
		}
		if(n>=200){
			memset(sum,0,sizeof(sum));
			cnt1=cnt2=0;
			for(int i = 1;i <= n;i++){
				cha1[i]=a[i][1]-a[i][2];
				cha2[i]=a[i][2]-a[i][1];
				if(cha1[i]<0) cha1[i]=20005;
				if(cha2[i]<0) cha2[i]=20005;
			}
			sort(cha1+1,cha1+n+1,cmp);
			sort(cha2+1,cha2+n+1,cmp);
			for(int i = 1;i <= n;i++){
				if(a[i][1]>=a[i][2]){
					sum[i]=sum[i-1]+a[i][1];
					cnt1++;
				}
				else{
					sum[i]=sum[i-1]+a[i][2];
					cnt2++;
				}
			}
			p=0;
			while(cnt1>n/2){
				sum[n]-=cha1[++p];
				cnt1--;
				cnt2++;
			}
			p=0;
			while(cnt2>n/2){
				sum[n]-=cha2[++p];
				cnt2--;
				cnt1++;
			}
			cout << sum[n] << "\n";
			continue;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				for(int k = 1;k <= min(n/2,i);k++){
					if(j==1){
						dp[i][j][k]=max(dp[i-1][j][k-1],max(dp[i-1][2][min(n/2,i-1)],dp[i-1][3][min(n/2,i-1)]))+a[i][j];
					}
					if(j==2){
						dp[i][j][k]=max(dp[i-1][j][k-1],max(dp[i-1][1][min(n/2,i-1)],dp[i-1][3][min(n/2,i-1)]))+a[i][j];
					}
					if(j==3){
						dp[i][j][k]=max(dp[i-1][j][k-1],max(dp[i-1][1][min(n/2,i-1)],dp[i-1][2][min(n/2,i-1)]))+a[i][j];
					}
				}
			}
		}
		for(int j = 1;j <= 3;j++){
			maxn=max(maxn,dp[n][j][n/2]);
		}
		cout << maxn << "\n";
	}
	return 0;
}
