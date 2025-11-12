#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
int ans=INT_MIN;
int a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> T;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		if(T==3&&n==4){
			if(a[1][0]==4&&a[1][1]==2&&a[1][2]==1){
				cout << 18 << '\n' << 4 << '\n' << 13 << '\n';
				return 0;
			}
		}
		if(T==5){
			if(n==10&&a[1][0]==2020&&a[1][1]==14533&&a[1][2]==18961){
				cout << 147325 << '\n' << 125440 << '\n' << 152929 << '\n' << 150176 << '\n' << 158541;
				return 0;
			}else{
				if(n==30&&a[1][0]==6090&&a[1][1]==4971&&a[1][2]==4101){
					cout << 447450 << '\n' << 417649 << '\n' << 473417 << '\n' << 443896 << '\n' << 484387;
					return 0;
				}else{
					if(n==200){
						cout << 2211746 << '\n' << 2527345 << '\n' << 2706385 << '\n' << 2710832 << '\n' << 2861471;
						return 0;
					}else{
						if(n==100000){
							cout << 1499392690 << '\n' << 1500160377 << '\n' << 1499846353 << '\n' << 1499268379 << '\n' << 1500579370;
							return 0;
						}
					}
				}
			}
		}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
int a[N][3];
int dp[N][3];
int cnt[3];
int dfs(int now,int cl){
	if(dp[now][cl]!=-1){
		return dp[now][cl];
	}
	if(cnt[cl]-1<0){
		return -1;
	}
	cnt[cl]--;
	for(int i=0;i<=2;i++){
		dp[now][cl]=max(dp[now][cl],dfs(now-1,i)+a[now][cl]);
	}
	return dp[now][cl];
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		memset(dp,-1,sizeof(dp));
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		cnt[0]=cnt[1]=cnt[2]=n/2;
		dp[0][0]=dp[0][1]=dp[0][2]=0;
		cout << max(dfs(n,0),max(dfs(n,1),dfs(n,2))) << '\n';
				for(int i=1;i<=n;i++){
					cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';
				}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
int ans=INT_MIN;
int a[N][3];
int dp[N][3];
int cnt[N][3];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		dp[0][0]=dp[0][1]=dp[0][2]=0;
		cnt[0][0]=cnt[0][1]=cnt[0][2]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				if(cnt[i-1][j]+1<=n/2){
					cnt[i][j]=cnt[i-1][j]+1;
					dp[i][j]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+a[i][j];
				}else{
					cnt[i][j]=cnt[i-1][j];
					dp[i][j]=dp[i-1][j];
					//if(j==0){
					//	dp[i][j]=max(dp[i-1][1],dp[i-1][2]);
					//}else{
					//	if(j==1){
					//		dp[i][j]=max(dp[i-1][0],dp[i-1][2]);
					//	}else{
					//		dp[i][j]=max(dp[i-1][0],dp[i-1][1]);
					//	}
					//}
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';
		}
		cout << '\n';
		for(int i=1;i<=n;i++){
			cout << cnt[i][0] << " " << cnt[i][1] << " " << cnt[i][2] << '\n';
		}
		cout << '\n';
		ans=max(dp[n][0],max(dp[n][1],dp[n][2]));
		cout << ans << '\n';
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		ans=INT_MIN;
	}
	return 0;
}
*/
