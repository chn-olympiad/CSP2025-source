#include<bits/stdc++.h>
using namespace std;
const int N=205;
struct node{
	int a,b,c;
}a[N];
int n;
int dp[N][N/2][N/2][N/2];
int main(){
	long long int u=clock();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
while(t--){
	//memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int ck1=0;ck1<=n/2;ck1++){
			for(int ck2=0;ck2<=n/2;ck2++){
				for(int ck3=0;ck3<=n/2;ck3++){
					if(ck1+ck2+ck3>i){
						break;
					}
					dp[i][ck1][ck2][ck3]=dp[i-1][ck1][ck2][ck3];
					if(ck1){
						dp[i][ck1][ck2][ck3]=max(dp[i][ck1][ck2][ck3],dp[i-1][ck1-1][ck2][ck3]+a[i].a);
					}
					if(ck2){
						dp[i][ck1][ck2][ck3]=max(dp[i][ck1][ck2][ck3],dp[i-1][ck1][ck2-1][ck3]+a[i].b);
					}
					if(ck3){
						dp[i][ck1][ck2][ck3]=max(dp[i][ck1][ck2][ck3],dp[i-1][ck1][ck2][ck3-1]+a[i].c);
					}
					ans=max(ans,dp[i][ck1][ck2][ck3]);
				}
			}
		}
	}
	//for(int ck1=1;ck1<=n/2+1;ck1++){
	//	for(int ck2=1;ck2<=n/2+1;ck2++){
	//		for(int ck3=1;ck3<=n/2+1;ck3++){
	//			cout<<dp[n-1][ck1][ck2][ck3]<<" ";
	//		}cout<<endl;
	//	}cout<<endl;
	//}cout<<endl;
	cout<<ans<<endl;
}
cout<<(clock()-u)/1000;
	return 0;
}
