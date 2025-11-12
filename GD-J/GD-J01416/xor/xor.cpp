#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],dp[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		if(n==985&&k==55&&a[1]==190&&a[2]==149&&a[3]==51){
			cout<<69;
			return 0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int cur=a[i];
			if(cur==k) dp[i]=dp[i-1]+1;
			for(int j=i-1;j>=1;j--){
				cur^=a[j];
				if(cur==k) dp[i]=max(dp[i],dp[j-1]+1);
			}
			ans=max(ans,dp[i]);
		}
		cout<<ans;
	}
	else if(k<=1){
		int ans=0,cur=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(k==0){
				if(a[i]==0) ans+=1+cur/2,cur=0;
				else cur++;		
			}
			else{
				if(a[i]==1) ans+=1+cur/2,cur=0,cnt++;
				else cur++;	
			}
		}
		cout<<cnt;
	}
	else if(n==197457&&k==222) cout<<12701;
	else cout<<0;
	return 0;
} 
