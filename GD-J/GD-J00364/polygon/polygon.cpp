#include<bits/stdc++.h>
using namespace std;
long long p=998244353;
long long a[10053],n;
//long long dp[553][553][3];
//int main(){
////	freopen("polygon3.in","r",stdin);
////	freopen("polygon3.out","w",stdout);
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	//for(int i=2;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j][0]=-0x3f3f3f3f3f3f3f3f;
//	for(int i=1;i<=n;i++){
//		for(int k=1;k<i;k++){
//			for(int j=1;j<=n;j++){
////				if(a[i]+dp[i][j][1]>2*max(a[i],dp[i][j][2]))dp[i][j][0]+=(dp[k][j-a[i]][0]+1)%p,dp[i][j][1]=max(a[i],dp[i][j][2]);
////				dp[i][j][0]=(dp[k][j-a[i]][0])%p,dp[i][j][1]=max(a[i],dp[i][j][2]);
//				if(a[i]+dp[k][j][1]>2*dp[k][j][2]){
//					dp[i][j][0]+=dp[k][j][0]%p+(k>=3); 
//					dp[i][j][1]=max(dp[k][j][1]+a[i],dp[k][j][1]);
//					dp[i][j][2]=max(a[i],dp[k][j][2]);
//				}else{
//					dp[i][j][0]+=dp[k][j][0]%p; 
//					dp[i][j][1]=max(dp[k][j][1]+a[i],dp[k][j][1]);
//					dp[i][j][2]=max(a[i],dp[k][j][2]);
//				}
//			}
//		}
//		cout<<"i"<<i<<"\n";
//		for(int z=1;z<=n;z++){
//			cout<<dp[i][z][0]<<" "<<dp[i][z][1]<<" "<<dp[i][z][2]<<"\n";
//		}
//	}
//	long long ans=0;
//	for(int i=1;i<=n;i++){
//		if(dp[n][i][1]>0)ans=(ans+max(dp[n][i][0],0LL))%p;
//	}
//	cout<<ans;
//	return 0;
//}
long long dfs(long long x,long long sc,long long ms,long long cn){
	if(x>n&&(sc>2*ms&&(cn>=3))){
//		cout<<sc<<"  "<<ms<<"  "<<cn<<"\n";
		return 1;	
	}
	if(x>n)return 0;
	int cnt=0;
	cnt+=dfs(x+1,sc+a[x],max(ms,a[x]),cn+1);
	cnt=cnt%p;
	cnt+=dfs(x+1,sc,ms,cn);
	cnt=cnt%p;
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	long long ans=dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
