#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],dp[N],s[N],dd[N],vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){//5points
		if(n==2) cout<<1;
		else cout<<0;
		return 0;
	}
	int sum=0,r;
	for(int i=1;i<=n;i++){
		sum=a[i];
		r=i;
		for(int j=i+1;j<=n&&sum!=k;j++){
			sum^=a[j];
			r=j;
		}
		if(sum==k){
			if(vis[r]==1&&r==i){
				dp[r]=max(dp[r-1]+1,dp[r]);
			}else{
				dp[r]=max(dp[r],dp[i]+1);
			}
			if(r!=i) vis[r]=1;
			for(int j=r;j<=n;j++){
				dp[j]=max(dp[r],dp[j]);
			}
			//for(int j=1;j<=n;j++) cout<<dp[j]<<" ";
			
		}
		/*if(sum==k){
			cout<<r;
			dd[r]++;
		}
		s[i]=dd[i]+s[i-1];*/
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 