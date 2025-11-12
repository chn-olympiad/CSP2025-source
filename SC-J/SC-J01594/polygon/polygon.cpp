#include<bits/stdc++.h>
using namespace std;
long long dp[5050][5050]{};
long long c(int u,int o){
	if(dp[u][o]!=0){
		return dp[u][o];
	}
	long long m=0;
	if(o>3){
		if(u==o) m++;
		else m=m+c(u-1,o)+c(u-1,o-1);
		dp[u][o]=m%998244353;
	}
	else{
		for(int i=u;i>=3;i--){
			m=m+(i*i-3*i+2)/2;
		}
		dp[u][o]=m%998244353;
	}
	return m;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int stick[n],a=-1;
	for(int i=0;i<n;i++){
		cin>>stick[i];
		a=max(a,stick[i]);
	}
	sort(stick,stick+n);
	if(n<=3){
		int ans1=0;
		if(stick[0]+stick[1]+stick[2]>2*stick[2]){
			ans1++;
			cout<<ans1;
		}
		else cout<<ans1;
	}
	if(a==1){
		long long ans2=0;
		for(int i=3;i<=n;i++) ans2=ans2+c(n,i);
		cout<<ans2%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}