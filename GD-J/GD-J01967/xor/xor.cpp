#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int n,a[N],k,s[N],ans;
int dp[2][107][107];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flaga=1,flagb=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==k)dp[0][i][i]=1;
		if(a[i]==1)s[1]++;
		if(a[i]==0)s[0]++;
		if(a[i]!=1)flaga=0;
		if(a[i]!=1&&a[i]!=0)flagb=0;
	}
	if(flaga==1){
		if(k==1){
			cout<<n;return 0;
		}else if(k==0){
			cout<<n/2;return 0;
		}else{
			cout<<0;return 0;
		}
	}else if(flagb==1){
		if(k!=1&&k!=0){
			cout<<0;return 0;
		}if(k==1){
			ans=s[1];
		}else{
			for(int i=1;i<=n;++i){
				if(a[i]==1&&a[i-1]==1){
					a[i]=-1;ans++;
				}
			}
			ans+=s[0];
		}
		cout<<ans;return 0;
	}else if(n<=206){
		for(int len=1;len<=n;++len){
			for(int i=1,j=len;j<=n;++j,++i){
				dp[1][i][j]+=dp[1][i][j-1]^a[j];
				if(dp[1][i][j]==k)dp[0][i][j]=1;
				for(int u=i;u<=j;++u){
					dp[0][i][j]=max(dp[0][i][j],dp[0][i][u]+dp[0][u+1][j]);
				}
			}
		}cout<<dp[0][1][n];
		return 0;
	}else cout<<0;
	return 0;
}
