#include<bits/stdc++.h> 
using namespace std;
long long maxn(long long x,long long y){
	if(x>=y)return x;
	return y;
}
struct shu{
	int a=0;int b=0;int c=0;
};
void solve()
{
	int n;cin>>n;shu dpp[1000];
     vector<int>sum(3*n+2);
     for(int i=1;i<=3*n;i++)
     {
         cin>>sum[i];
	 }int a=0,b=0,c=0;
	 long long dp[1000]={};
	 dp[1]=sum[1],dp[2]=sum[2],dp[3]=sum[3];
	 dpp[1].a=1,dpp[2].b=1,dpp[3].c=1;
	 for(int i=4;i<=3*n;i++){
	 	   if(i%3==1){
	 	   	   if(dpp[i-1].a+1<=n/2&&dp[i]<dp[i-1]+dp[i]){dp[i]=dp[i-1]+sum[i],dpp[i]=dpp[i-1];}
	 	   	   if(dpp[i-2].a+1<=n/2&&dp[i]<dp[i-2]+dp[i]){dp[i]=dp[i-2]+sum[i],dpp[i]=dpp[i-2];}
	 	   	   if(dpp[i-3].a+1<=n/2&&dp[i]<dp[i-3]+dp[i]){dp[i]=dp[i-3]+sum[i],dpp[i]=dpp[i-3];}
				   dpp[i].a++;
			}
			 if(i%3==2){
	 	   	   if(dpp[i-2].b+1<=n/2&&dp[i]<dp[i-2]+dp[i]){dp[i]=dp[i-2]+sum[i],dpp[i]=dpp[i-2];}
	 	   	   if(dpp[i-3].b+1<=n/2&&dp[i]<dp[i-3]+dp[i]){dp[i]=dp[i-3]+sum[i],dpp[i]=dpp[i-3];}
	 	   	   if(dpp[i-4].b+1<=n/2&&dp[i]<dp[i-4]+dp[i]){dp[i]=dp[i-4]+sum[i],dpp[i]=dpp[i-4];}
				   dpp[i].b++;
			}
				   
			if(i%3==0) {
				if(dpp[i-3].c+1<=n/2&&dp[i]<dp[i-3]+dp[i]){dp[i]=dp[i-3]+sum[i],dpp[i]=dpp[i-3];}
	 	   	   if(dpp[i-4].c+1<=n/2&&dp[i]<dp[i-4]+dp[i]){dp[i]=dp[i-4]+sum[i],dpp[i]=dpp[i-4];}
	 	   	   if(dpp[i-5].c+1<=n/2&&dp[i]<dp[i-5]+dp[i]){dp[i]=dp[i-5]+sum[i],dpp[i]=dpp[i-5];}
				   dpp[i].c++;
			}
	  }
cout<<maxn(maxn(dp[3*n],dp[3*n-1]),dp[3*n-2]);
}
int main()
{

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--) 
	{
		solve();
	}
	return 0;
}
