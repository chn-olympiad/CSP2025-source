#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],s[N],dp[N][2];
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i][0],max(dp[i-1][0],dp[i-1][1]));
		int r=0; 
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				r=j;
				break;	
			}
		}
		if(r==0) continue;
		//cout<<i<<' '<<r<<endl;
		dp[r][1]=max(dp[r][1],dp[i][0]+1);
	}
//	for(int i=1;i<=n;i++){
//		cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
//	}
	cout<<max(dp[n][1],dp[n][0]);
	return 0;
}