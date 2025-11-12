#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int s[200005];
int dp[200005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	if(n==1){
		int x;
		cin>>x;
		if(x!=k)cout<<0;
		else cout<<1;
		return 0;
	}
	if(n==2){
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		int q=x^y;
		int ans=0;
		if(x==k)ans++;
		if(q==k){
			cout<<1;
			return 0;
		}
		if(y==k)ans++;
		cout<<ans;
		return 0; 
	}
	if(k<=1){
		if(k==0){
			int sum=0;
			int cnt=0; 
			for(int i=1;i<=n;i++)cin>>s[i],sum+=s[i],cnt+=(s[i]==0);
			if(sum==0)cout<<n;
			else if(sum==n)cout<<n/2;
			else cout<<cnt+sum/2; 
		}
		if(k==1){
			int sum=0;
			int cnt=0;
			for(int i=1;i<=n;i++)cin>>s[i],sum+=(s[i]==1),cnt+=(s[i]==0);
			cout<<max(sum,cnt);
		}
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<i-1;j++){
			int t=s[i]^s[j];
			if(t==k){
				dp[i]=max(dp[i],dp[j]+1);
			}
			if(s[i]==k){
				dp[i]=max(dp[i],dp[j+1]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}