#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int lt[4][N];
int cnt[3][3];
int dp[2][3];
int ipt[3];
int f[3][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,mem,ans,m=0,ms=0;
	int now=0,pre=1;
	cin>>t;
	while(t--){
		cin>>mem;
		
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<mem;i++){
			m=ms=0;
			swap(now,pre);
			cin>>ipt[0]>>ipt[1]>>ipt[2];
			//cout<<ipt[0]<<ipt[1]<<ipt[2];
			for(int j=0;j<3;j++){
				ms=m=0;
				for(int k=0;k<3;k++){
					if(cnt[k][j]==mem/2){

						continue;
					}
					else if(dp[pre][k]>m){

						m=dp[pre][k];
						ms=k;
					}

				}
				dp[now][j]=m+ipt[j];
				// cout<<dp[now][j]<<' ';
				for(int a=0;a<3;a++){
					// cout<<ms;
					if(j==a)f[j][a]=cnt[ms][a]+1;
					else f[j][a]=cnt[ms][a];
					
				}
				
		

			}


			
			for(int p=0;p<3;p++){
				for(int q=0;q<3;q++){
					cnt[p][q]=f[p][q];
					 // cout<<cnt[p][q]<<' ';
				}
				 
				
			}
			
			 // cout<<dp[now][0]<<' '<<dp[now][1]<<' '<<dp[now][2]<<endl;
			
		}
		
		 cout<<max(dp[now][0],max(dp[now][1],dp[now][2]))<<endl;


	

	}
	// ios::sync_with_stdio(false);


	return 0;
}