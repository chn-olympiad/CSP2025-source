#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int T;
int n;
int a[N][4];
int dp[N][4];
int cnt[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		for(int i=2;i<=n+1;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=2;i<=n+1;i++){
			int maxn=max(max(a[i][1],a[i][2]),a[i][3]);
//			cout<<maxn<<endl;
			if(maxn==a[i][1]){
//				cout<<1<<" ";
				if(cnt[1]+1<=(n/2)){
//					cout<<1<<endl;
					dp[i][1]=dp[i-1][1]+a[i][1];
					dp[i][2]=dp[i-1][2];
					dp[i][3]=dp[i-1][3];
					cnt[1]++;
				}else{
//					cout<<2<<" ";
					if(dp[i-1][2]+a[i-1][2]>dp[i-1][3]+a[i-1][3]){
//						cout<<1<<endl;
						dp[i][1]=dp[i-2][1]+a[i][1];
						dp[i][2]=dp[i-1][2]+a[i-1][2];
						dp[i][3]=dp[i-1][3];
						cnt[2]++;
					}else{
//						cout<<2<<endl;
						dp[i][1]=dp[i-2][1]+a[i][1];
						dp[i][2]=dp[i-1][2];
						dp[i][3]=dp[i-1][3]+a[i-1][3];
						cnt[3]++;
					}
				}
			}else if(maxn==a[i][2]){
//				cout<<2<<" ";
				if(cnt[2]+1<=(n/2)){
//					cout<<1<<endl;
					dp[i][1]=dp[i-1][1];
					dp[i][2]=dp[i-1][2]+a[i][2];
					dp[i][3]=dp[i-1][3];
					cnt[2]++;
				}else{
//					cout<<2<<" ";
					if(dp[i-1][1]+a[i-1][1]>dp[i-1][3]+a[i-1][3]){
						cout<<1<<endl;
						dp[i][1]=dp[i-1][1]+a[i-1][1];
						dp[i][2]=dp[i-2][2]+a[i][2];
						dp[i][3]=dp[i-1][3];
						cnt[1]++;
					}else{
//						cout<<2<<endl;
						dp[i][1]=dp[i-1][1];
						dp[i][2]=dp[i-2][2]+a[i][2];
						dp[i][3]=dp[i-1][3]+a[i-1][3];
						cnt[3]++;
					}
				}
			}else{
//				cout<<3<<" ";
				if(cnt[3]+1<=(n/2)){
//					cout<<1<<endl;
					dp[i][1]=dp[i-1][1];
					dp[i][2]=dp[i-1][2];
					dp[i][3]=dp[i-1][3]+a[i][3];
					cnt[3]++;
				}else{
//					cout<<2<<" ";
					if(dp[i-1][1]+a[i-1][1]>dp[i-1][2]+a[i-1][2]){
//						cout<<1<<endl;
						dp[i][1]=dp[i-1][1]+a[i-1][1];
						dp[i][2]=dp[i-1][2];
						dp[i][3]=dp[i-2][3]+a[i][3];
						cnt[1]++;
					}else{
//						cout<<2<<endl;
						dp[i][1]=dp[i-1][1];
						dp[i][2]=dp[i-1][2]+a[i-1][2];
						dp[i][3]=dp[i-2][3]+a[i][3];
						cnt[2]++;
					}
				}
			}
		}
//		cout<<dp[n+1][1]<<" "<<dp[n+1][2]<<" "<<dp[n+1][3]<<endl;
		cout<<dp[n+1][1]+dp[n+1][2]+dp[n+1][3]<<endl;
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
