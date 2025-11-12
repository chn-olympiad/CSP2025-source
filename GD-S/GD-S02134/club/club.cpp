#include <bits/stdc++.h>
using namespace std;
long long dp[105][105][105];
long long a[100000+10][5];
long long h[100000+10];
long long t,n;
bool f=1;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			h[i]=a[i][1];
			if(a[i][2]!=0 || a[i][3]!=0){
				f=false;
			}
		}
		if(f){
			sort(h+1,h+n+1,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=h[i];
			}
			cout << sum << endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int a2=n/2;a2>=0;a2--){
				for(int b=n/2;b>=0;b--){
					for(int c=n/2;c>=0;c--){
						if(a2!=0){
							dp[a2][b][c]=max(dp[a2][b][c],dp[a2-1][b][c]+a[i][1]);
						}
						if(b!=0){
							dp[a2][b][c]=max(dp[a2][b][c],dp[a2][b-1][c]+a[i][2]);
						}
						if(c!=0){
							dp[a2][b][c]=max(dp[a2][b][c],dp[a2][b][c-1]+a[i][3]);
						}
					}
				}
			}
		}
		cout << dp[n/2][n/2][n/2] << endl;
	}
	return 0;
}
