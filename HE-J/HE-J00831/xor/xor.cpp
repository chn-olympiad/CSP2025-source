#include <bits/stdc++.h>
#define ll long long  
using namespace std;
const int MAXN=1e5+50;
ll a[MAXN],k,n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i]; 
//		x[i]=x[i-1]^a[i];
//	}  
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(x[i-1]^x[j-1]==k){
//				if(a[j]==k) dp[i][j]=dp[i][j-1]+1;
//				else dp[i][j]=maxn(dp[i-1][j-1],dp[i][j-1]);
//			}
//			else if(a[j]==k)	
//		}
//	}
	if(k==0) cout<<floor(n*1.0/2);
	else if(k==1){
		int ans=0;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){ 
				ans++;
			}
		} cout<<ans;
	}
	else{
		int ans=0;
		for(int i=2;i<=n;i++){
			int x=a[i],j=1; bool flag=true;
			while(a[i]){
				int t=a[i]%2;
				if(t==(a[i]>>(j-1)-k&0)){
					flag=false;
					break;
				} a[i]/=2;
			} ans+=flag;
		} cout<<ans-1;
	}
	return 0;
} //A+B<=30pts
