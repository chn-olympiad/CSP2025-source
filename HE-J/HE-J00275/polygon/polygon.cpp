#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,a[5010],dp[5011]={0},sum[5011],ans=0;
int mod(long long x){
	return (x%p+p)%p;
}
int lowbit(int x){
	return x&(-x);
}
void upset(int x,int k){
	while(x<=m+1){
		sum[x]=mod(1ll*sum[x]+k);
		x+=lowbit(x);
	}
}
int sumk(int x){
	int ans=0;
	while(x>0){
		ans=mod(1ll*ans+sum[x]);
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		m=max(m,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		//cout<<i<<endl;
		//for(int j=1;j<=m+1;j++) cout<<" "<<j<<" "<<dp[j]<<endl;
		ans=mod(1ll*ans+sumk(m+1)-sumk(a[i]));
		for(int j=m+1;j>=m+1-a[i];j--){
			upset(m+1,dp[j]);
			dp[m+1]=mod(1ll*dp[m+1]+dp[j]);
		}
		for(int j=m;j>=a[i];j--){
			upset(j,dp[j-a[i]]);
			dp[j]=mod(1ll*dp[j]+dp[j-a[i]]);
		}
	}
	cout<<ans;
	return 0;
}
