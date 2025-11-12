#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
ll n,k,a[500005],pre[500005],dp[500005];
void solve(){
	if(k==1){
		ll cnt=0;
		for(int i=1;i<=n;i++) cnt+=a[i];
		cout<<cnt;
	}else{
		ll cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(!a[i]){
				cnt++;
				cnt+=sum/2;
				sum=0;
			}else sum++;

		}
		cnt+=sum/2; 
		cout<<cnt;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	if(n>1e3&&k<=1){ solve();return 0;}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--) if((pre[i]^pre[j-1])==k){	dp[i]=max(dp[i],dp[j-1]+1);break;}
//		cout<<dp[i]<< " ";
	}
	cout<<dp[n];
	return 0;
}
