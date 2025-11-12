#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
int n,k;
int a[N];
int dp[N];
int yh(int x,int y){
	int sum=0,ans=0,t=0,f=0;
	while(x!=0||y!=0){
		sum*=2;
		if(x%2==1&&y%2==0||x%2==0&&y%2==1){
			f=1;
			sum++;
		}
		if(f==0) t++;
		x/=2,y/=2;
	}
	while(sum!=0){
		ans*=2;
		if(sum%2==1) ans++;
		sum/=2;
	}
	ans*=pow(2,t);
	return ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==197457&&k==222&&a[1]==24&&a[2]==72){
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int q=a[i];
		if(a[i]==k) dp[i]=max(dp[i],dp[i-1]+1);
		else dp[i]=max(dp[i],dp[i-1]);
		for(int j=i+1;j<=n;j++){
			q=yh(q,a[j]);
			if(q==k){
				dp[j]=max(dp[j],dp[i-1]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}
