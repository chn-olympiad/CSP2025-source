#include<bits/stdc++.h>
using namespace std;
int n,k;
int b[500005];
int dp[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;  
	for(int i=1;i<=n;i++){
		cin>>b[i];
		dp[i]=-1;
	}
	
	for(int i=1;i<=n;i++){
		if(dp[i]==k){
			dp[i]=dp[i-1]+1;
		}
		else{
			int c=0,cnt=0;
			for(int j=i;j<=n;j++){
				c^=b[j];
				if(c==k){
					cnt=j;
					break;	
				} 
			}//cout<<cnt<<" "<<dp[i]<<endl;
			if(cnt!=0){
				dp[cnt]=max(dp[cnt],dp[i-1]+1);
				f[cnt]=max(f[cnt],i);
			}
	}
		//cout<<i<<" "<<dp[i]<<endl;
		if(f[i]>f[i-1]&&dp[i]<0){dp[i]+=dp[i-1];
		}
		else{
			if(dp[i]<0&&f[i]>f[i-1]){
				dp[i]=dp[i-1];
			}
			else dp[i]=max(dp[i],dp[i-1]);
		} 
		//cout<<i<<" "<<dp[i]<<endl; 
	}
	cout<<dp[n];
	return 0;
}
