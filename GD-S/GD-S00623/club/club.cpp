#include<bits/stdc++.h>
using namespace std;
const int N=200+10;
int a[100010][5],T,n,fl,x[100010];
int dp[N][N][N];
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) fl=1;
			if(fl==0) x[i]=a[i][1];
		}
		if(fl==0){
			sort(x+1,x+1+n);
			int ans=0; 
			for(int i=n;i>n/2;i--){
				ans+=x[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i-j;k++){
					if(j+k>i) break;
					int o=i-j-k;
					if(o!=0) dp[i][j][k]=max(dp[i][j][k],(dp[i-1][j][k]+a[i][3]));
					if(k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if(j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
				}
			}
		}
		int maxx=0;
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n-j;k++){
					if(j+k>n) break;
					int o=n-j-k;
					int ll=n/2;
					if(j<=ll&&k<=ll&&o<=ll) maxx=max(maxx,dp[n][j][k]);
				}
			}
		cout<<maxx<<"\n";
	}
} 
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
/*
1
2
10 9 8
4 0 0
*/ 
