#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
vector<vector<int> > manyi;

void read(){
	cin>>n;
	manyi.resize(n,vector<int>(3));
	for(int i=0;i<n;i++)
	    for(int j=0;j<3;j++)
	        cin>>manyi[i][j];
	   
	
	return;
}
int max2(int a,int b){
	if(a>=b)
	   return a;
	else
	   return b;
}

vector<vector<int> > dp;



signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++){

		read();

		
        for(int i=0;i<n;i++){

        	for(int j=0;j<dp.size()&&j<n/2;j++){
			    

        	    for(int k=0;k<dp[j].size()&&k<n/2;k++){ 

                    if(j==dp.size()-1)
                        dp[j+1].push_back((max2(dp[j][k],max2(dp[j][k]+manyi[i][0],dp[j][k]+manyi[i][1]))));
                    
                    else if(k==dp.size()-1)
                        dp[j].push_back((max2(dp[j][k],max2(dp[j][k]+manyi[i][0],dp[j][k]+manyi[i][1]))));
                    else{
					
        	               dp[j+1][k+1]=(max2(dp[j][k],max2(dp[j][k]+manyi[i][0],dp[j][k]+manyi[i][1]))) ;
        	               cout<<"it"<<j<<k<<dp[j][k]<<"end"<<endl;

        	        }
        	        if(i-j-k<=n/2)
        	            dp[j][k]=max2(dp[j][k],dp[j][k]+manyi[i][2]);        

		        }
		    } 
	    } 
		int ans=0;
	    for(int i=1;i<=n;i++)
	    	ans=max2(ans,dp[i][n+2-i]);
	    cout<<ans;
	}
			



	
	

	return 0;
}

