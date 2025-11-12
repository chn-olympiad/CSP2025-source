#include<bits/stdc++.h>
using namespace std;
long long dp[510][510][510]={0},c[510]={0};
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int n,m,p=998244353;
long long ans=0;
string s;
cin>>n>>m;
cin>>s;
for(int i=0;i<n;i++){
	int x;
	cin>>x;
	c[x]++;
}
for(int i=1;i<=n;i++){
	c[i]=c[i-1]+c[i];
	}

for(int k=1;k<=n-1;k++){
	dp[n-1][k][1]=(s[n-1]-'0')*(n-c[k])%p;
	dp[n-1][k][0]=n;
}
for(int i=n-2;i>=0;i--){
	for(int k=1;i<=n-1;k++){
		for(int mm=1;mm<=n-1;mm++){
			
		dp[i][k][mm]=dp[i+1][k+1][mm];
		dp[i][k][mm]+=(s[i]-'0')*(n-c[k])%p*dp[i+1][k][mm-1]%p;
		}
		}
	}
for(int i=0;i<=n-1;i++){
	for(int j=m;j<=n;j++){
		ans+=dp[0][i][j];
		}
	}
cout<<ans;
return 0;
}
