#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long dp[N],a[N],vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt;
	for(int i=1;i<=n;i++){
		cnt=a[i];
		if(cnt==k){
			dp[i]++;
			vis[i]=1;
		}
		for(int j=i-1;j>0;j--){
			if(vis[j]>0){
				dp[i]=max(dp[j]+vis[i],dp[i]);
				break;
			}
			if(vis[i]==0){
				cnt=cnt|a[j];
				if(cnt==k){
					dp[i]++;
					vis[i]=1;
				}
			}
		}
	}
	cout<<dp[n];
	return 0;
} 
