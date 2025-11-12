#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t,n=3;
	cin>>t>>n;

	while(t--){
		vector<int> a1(n+1),a2(n+1),a3(n+1);
		vector<int> v(n+1,0);
		
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		vector<vector<int>> dp(n/2+1,vector<int>(4,0));
			
		for(int i=0;i<n/2;i++){
			
			int f;
			if(i==0) {
				f=0;
				for(int j=0;j<n;j++){
					if(a1[j]>dp[i][0]){
						dp[i][0]=a1[j];
						v[f]=0;
						v[j]=1;						
						f=j;					
						}
					}
				
				
				f=0;
				for(f;f<n;f++) if(v[f]==0) break;
				
				for(int j=0;j<n;j++){
					if(a2[j]+dp[i][0]>dp[i][1]){
						if(v[j]==0){
							dp[i][1]=a2[j]+dp[i][0];
							v[f]=0;
							v[j]=1;
							f=j;						
						}
						else{
							if(a2[j]>dp[i][1]){
								dp[i][1]=a2[j];
								v[f]=0;
								f=j;
							}
						}			
					}
				}
				
				f=0;
				for(f;f<n;f++) if(v[f]==0) break;
				
				for(int j=0;j<n;j++){
					if(a3[j]+dp[i][1]>dp[i][2]){
						if(v[j]==0){
							dp[i][2]=a3[j]+dp[i][1];
							v[f]=0;
							v[j]=1;
							f=j;						
						}
						else{
							if(a3[j]>dp[i][2]){
								dp[i][2]=a3[j];
								v[f]=0;
								f=j;
							}
						}			
					}
				}
			}
			else{
				f=0;
				for(f;f<n;f++) if(v[f]==0) break;
				
				for(int j=0;j<n;j++){
					if(a1[j]+dp[i-1][0]>dp[i][0]){
						dp[i][0]=a1[j]+dp[i-1][0];
						v[f]=0;
						v[j]=1;						
						f=j;					
						}
					}
				
				
				f=0;
				for(f;f<n;f++) if(v[f]==0) break;
				
				for(int j=0;j<n;j++){
					if(a2[j]+dp[i][0]>dp[i][1]){
						if(v[j]==0){
							dp[i][1]=a2[j]+dp[i][0];
							v[f]=0;
							v[j]=1;
							f=j;
							if(a2[j]+dp[i-1][1]>dp[i][1]){
								dp[i][1]=a2[j]+dp[i-1][1];
							}												
						}
						else{
							if(a2[j]>dp[i][1]){
								dp[i][1]=a2[j];
								v[f]=0;
								f=j;								
							}
							if(a2[j]+dp[i-1][1]>dp[i][1]){
								dp[i][1]=a2[j]+dp[i-1][1];
								v[f]=0;
								f=j;
							}
						}			
					}

				}
				
				f=0;
				for(f;f<n;f++) if(v[f]==0) break;
				
				for(int j=0;j<n;j++){
					if(a3[j]+dp[i][1]>dp[i][2]){
						if(v[j]==0){
							dp[i][2]=a3[j]+dp[i][1];
							v[f]=0;
							v[j]=1;
							f=j;
							if(a3[j]+dp[i-1][2]>dp[i][2]){
								dp[i][2]=a3[j]+dp[i-1][2];
							}						
						}
						else{
							if(a3[j]>dp[i][2]){
								dp[i][2]=a3[j];
								v[f]=0;
								f=j;
							}
							if(a3[j]+dp[i-1][2]>dp[i][2]){
								dp[i][2]=a3[j]+dp[i-1][2];
								v[f]=0;
								f=j;
							}
						}			
					}
				}				
			}
			 
		}
		cout<<dp[n/2-1][2]<<endl;								
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
}


