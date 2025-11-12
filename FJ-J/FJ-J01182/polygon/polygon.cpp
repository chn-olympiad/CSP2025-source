#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5411],s[5411],dp[5411],cnt;
long long search(int dep){
	if(dp[dep]==-1){
		if(dep==n-2){
			if(a[dep]<a[dep+1]+a[dep+2]){
				dp[dep]=1;
			}
			else{
				dp[dep]=0;
			}
		}
		else{
			dp[dep]=0;
			for(int i=dep+1;i<=n-2;i++){
				if(a[dep]<s[i]){
					dp[dep]+=search(i);
					dp[dep]%=998244353;
				}
			}
			if(a[dep]<s[n-1])
			dp[dep]+=1;
		}
	}
	return dp[dep];
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--){
		s[i]=(s[i+1]+a[i])%998244353;
	}
	cnt=search(1)%998244353;
	cout<<cnt;
	return 0;
}

