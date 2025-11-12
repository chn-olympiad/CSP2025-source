//#include<bits/stdc++.h>
//using namespace std;
//const int N=int(1e5+10);
//int w[3][N],dp[3][N];
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
////	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
//	freopen("C:/Users/Administrator/Documents/problem/club/club1.in","r",stdin);
//	int T,n;cin>>T;
//	while(T--){
//		cin>>n;
//		for(int i=0;i<n;i++) cin>>w[0][i]>>w[1][i]>>w[2][i];
//		memset(dp,0,sizeof(int)*(n+5));
//		memset(&dp[1],0,sizeof(int)*(n+5));
//		memset(&dp[2],0,sizeof(int)*(n+5));
//		for(int i=0;i<n;i++){
//			for(int j=n/2;j>=1;j--){
//				for(int k=0;k<3;k++){
//					int v=dp[k][j-1]+w[k][i],ss=v;
//					for(int kk=0;kk<3;kk++)
//						if(kk!=k) ss+=dp[kk][j];
//					if(dp[0][j]+dp[1][j]+dp[2][j]<ss)
//						dp[k][j]=v;
//				}
//			}
//		}
//		cout<<dp[0][n/2]<<' '<<dp[1][n/2]<<' '<<dp[2][n/2]<<'\n';
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int N=int(1e5+10);
int w[N][3],n,tt[3];
long long ans;
void dfs(int d,long long l){
	if(d>=n){
		ans=max(ans,l);
		return;
	}
	for(int i=0;i<3;i++){
		if(tt[i]<(n>>1)){
			tt[i]++;
			dfs(d+1,l+w[d][i]);
			tt[i]--;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
//	freopen("C:/Users/Administrator/Documents/problem/club/club1.in","r",stdin);
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>w[i][0]>>w[i][1]>>w[i][2];
		ans=0;
		dfs(0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
