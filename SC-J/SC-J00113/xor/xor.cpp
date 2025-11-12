#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],dp[5000010],s[500010],t[500010],sr[500010],cnt,ans,f1=1;
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
		if(!(a[i]==1||a[i]==0))f1=0;
	}
	if(n<=1010){
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(k==(s[r]^s[l-1])){
				sr[++cnt]=r;
				t[r]=l;
				dp[r]=1;
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<t[i];j++){
			dp[i]=max(dp[i],dp[j]+1);
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
	}
	if(f1==1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==1&&a[i+1]==1){
					ans++;i++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
}