#include<bits/stdc++.h>
using namespace std;
const int N=500055;
int n,k,a[N],s[N],ans,dp[N];
int yihuo(int x,int y){
	int cnt=0,q,w,c=1;
	while(x!=0||y!=0){
		q=x%2;
		w=y%2;
		if(q!=w) cnt+=c;
		c*=2;
		x/=2;
		y/=2;
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=yihuo(s[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if(dp[j-1]<dp[i]) break;
			if(yihuo(s[i],s[j-1])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}
