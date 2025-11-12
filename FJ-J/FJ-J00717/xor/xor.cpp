#include<bits/stdc++.h>
using namespace std;
int a[1000001],f[1000001],p[1000001],dp[1000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,k,q=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=q+1;j<=i;j++){
			p[j]=a[i]^p[j];
			if(p[j]==k&&f[j]==0){
				f[j]=i;
				q=i;
			}
		}
	}
	dp[0]=-1;
	for(int i=1;i<=n;i++){
		if(f[i]==0)continue;
		for(int j=0;j<=n;j++){
			if(dp[j]==0||i<=dp[j])break;
			if(dp[j+1]!=0)dp[j+1]=min(dp[j+1],f[i]);
			else dp[j+1]=f[i];
		}
	}
	for(int i=0;i<=n;i++){
		if(dp[i]==0){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
}
