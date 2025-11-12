#include<bits/stdc++.h>
using namespace std;
const int m=998244353;
int a[5005],f,ans=0;
long long dp[5005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+(n+1));dp[1]=dp[2]=0;
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			dp[i]=dp[i-1]*2+((i-1)*i)/2;
			dp[i]=(dp[i]%m);
		}
		cout<<dp[n];
	}else{
		if(n==3){
			for(int i=1;i<=n;i++)f+=a[i];
			if(f>a[n]*2)cout<<1;
			else cout<<0;
	}
}
	return 0;
}

