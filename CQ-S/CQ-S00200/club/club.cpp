#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ss{
	int x,y,z;
}a[100100],b[100100],c[100100];
int t;
bool cmp1(ss a,ss b){
	return a.x>b.x;
} 
bool cmp2(ss a,ss b){
	return a.y>b.y;
} 
bool cmp3(ss a,ss b){
	return a.z>b.z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			b[i].x=a[i].x;
			b[i].y=a[i].y;
			b[i].z=a[i].z;
			c[i].x=a[i].x;
			c[i].y=a[i].y;
			c[i].z=a[i].z;
		}
		sort(a+1,a+n+1,cmp1);
		sort(b+1,b+n+1,cmp2);
		sort(c+1,c+n+1,cmp3);
		int ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=n/2;i++){
			ans1+=a[i].x;
		} 
		for(int i=n/2+1;i<=n;i++){
			ans1+=max(a[i].y,a[i].z);
		}
		for(int i=1;i<=n/2;i++){
			ans2+=b[i].y;
		} 
		for(int i=n/2+1;i<=n;i++){
			ans2+=max(b[i].x,a[i].z);
		}
		for(int i=1;i<=n/2;i++){
			ans3+=c[i].z;
		} 
		for(int i=n/2+1;i<=n;i++){
			ans3+=max(c[i].x,c[i].y);
		}
		cout<<max(ans1,max(ans2,ans3))<<'\n';
		
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
				
//				int maxxx=max(dp[i-1][1].ans,max(dp[i-1][2].ans,dp[i-1][3].ans)),maxid=0;
//				if(maxx=dp[i-1][1].ans){
//					maxid=1;
//					if(dp[i-1][maxid].yi<n/2){
//						dp[i][j].ans=maxxx+a[i][maxid];
//						dp[i][j].yi+=1;
//					}
//					else{
//						int maxc=max(dp[i-1][2].ans,dp[i-1][3].ans);
//						if(maxc==dp[i-1][2].ans){
//							maxid=2;
//							dp[i][j].ans=maxxx+a[i][maxid];
//							dp[i][j].er++;
//						}
//						else{
//							maxid=3;
//							dp[i][j].ans=maxxx+a[i][maxid];
//							dp[i][j].san++;
//						}
//					}
//					
//				}
//				else if(maxx=dp[i-1][2].ans){
//					maxid=2;
//					if(dp[i-1][maxid].er<n/2){
//						dp[i][j].ans=maxxx+a[i][maxid];
//						dp[i][j].er+=1;
//					}
//					else{
//						int maxc=max(dp[i-1][1].ans,dp[i-1][3].ans);
//						if(maxc==dp[i-1][1].ans){
//							maxid=1;
//							dp[i][j].ans=maxxx+a[i][maxid];
//							dp[i][j].yi++;
//						}
//						else{
//							maxid=3;
//							dp[i][j].ans=maxxx+a[i][maxid];
//							dp[i][j].san++;
//						}
//					}
//				}
//				else{
//					maxid=3;
//					if(dp[i-1][maxid].san<n/2){
//						dp[i][j].ans=maxxx+a[i][maxid];
//						dp[i][j].san+=1;
//					}
//					else{
//						int maxc=max(dp[i-1][1].ans,dp[i-1][2].ans);
//						if(maxc==dp[i-1][1].ans){
//							maxid=1;
//							dp[i][j].ans=maxxx+a[i][maxid];
//							dp[i][j].yi++;
//						}
//						else{
//							maxid=2;
//							dp[i][j].ans=maxxx+a[i][maxid];
//							dp[i][j].er++;
//						}
//					}
//				}	cout<<dp[i][j].ans<<" "<<dp[i][j].yi<<" "<<dp[i][j].er<<dp[i][j].san<<'\n';
//			}
			
//		} 
//		cout<<max(dp[n][1].ans,max(dp[n][2].ans,dp[n][3].ans))<<'\n';
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
//dp[i][j]表示第i个人在j中的满意度总和
//
//	dp[i][j].ans=max(dp[i-1][1].ans,dp[i-1][2].ans,dp[i-1][3].ans)+a[i][j];
//	if(j==1)dp[i][j].yi++;
//}
