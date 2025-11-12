#include<iostream>
#include<algorithm>
using namespace std;
int dp[5000][3];
int main(){
	int t;
	cin>>t;
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	while(t--){
		int n;
		cin>>n;
		int a[n+1],b[n+1],c[n+1];
		int sum=0;
		
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i]; 
			int m=max(a[i],max(b[i],c[i]));
			sum+=m;
		}
		if(n==2){
			int h=max(a[1],a[2]);
			int m=max(b[1],b[2]);
			int g=max(c[1],c[2]);
			cout<<max(h,m)+max(m,g);
			return 0;
		}
		cout<<sum;
	}

//		int b1[n+1],b2[n+1],b3[n+1];
//		
//		 
//		for(int i=1;i<=n;i++){
//			if(b1[i]+1<=n/2){
//				dp[i][0]+=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+a1[i];
//				b1[i]++;
//				k1+=dp[i][0];
//			}
//			if(b2[i]+1<=n/2){
//				dp[i][1]+=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+a2[i];
//				b2[i]++;
//				k2+=dp[i][1];
//			}
//			if(b1[i]+1<=n/2){
//				dp[i][2]+=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+a3[i];
//				b3[i]++;
//				k3+=dp[i][2];
//			}
//		
//		
//		}
//		cout<<max(k1,max(k2,k3));
	return 0;
	
}
		



