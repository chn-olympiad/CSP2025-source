#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,mst,a[5][100005],dp[5][100005],dpb[5][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		mst=n/2;
		for(int i=1;i<=n;i++) cin>>a[1][i]>>a[2][i]>>a[3][i];
		//dp?
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int mx=max(a[1][i],max(a[2][i],a[3][i]));
				dp[j][i]=dp[j][i-1]+mx;
			}	
		}
		//qc
//		for(int i=n;i>0;i++)
//			for(int j=1;j<=3;j++){
//				int mx=max(a[1][i],max(a[2][i],a[3][i]));
//				dpb[j][i]=dpb[j][i+1]+mx;
//			}
		for(int i=1;i<=n;i++) 
			ans=max(ans,dp[i][n]);
//			ans=max(ans,max(dp[i][n],dpb[i][1]));
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
