#include<bits/stdc++.h>
using namespace std;
int n,m;
int h[550];
int a[550],b[550];
int c[550];
long long ans;
long long d[550];
long long dp[550],mod=998244353;
//long long inv[550];
long long A[550][550];
//dp[i]表示至少有i个人的方案数
//dp[i]+=dp[i-1]*(d[j]-i+1)-dp[i-2]*(d[j]-i+2);
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	A[0][0]=1;
	for(int i=1;i<=n;i++){
		A[i][1]=i;
		A[i][0]=1;
		for(int j=2;j<=i;j++){
			A[i][j]=A[i][j-1]*(i-j+1);
			A[i][j]%=mod;
//			cout<<i<<' '<<j<<' '<<A[i][j]<<endl;
		}
	}
	char ch;
	for(int i=1;i<=n;i++){
		cin>>ch;
		h[i]=ch-'0';
		a[i]=a[i-1]+(h[i]==1);
		b[i]=b[i-1]+(h[i]==0);
	}
	a[n+1]=a[n];
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	for(int j=1,i=1;i<=n;i++){
		while(j<=n&&b[j]<c[i])j++;
		d[i]=a[i];
//		cout<<d[i]<<' ';
	}
//	cout<<endl;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		if(d[j]-i+1>0){
			dp[i]+=dp[i-1]*(d[j]-i+1)%mod;
			dp[i]%=mod;
			if(i-2>=0)dp[i]-=dp[i-2]%mod*(d[j]-i+2)%mod;
			dp[i]=(dp[i]+mod)%mod;
		}
		if(i>=m)ans+=dp[i]%mod*A[b[n]][n-i]%mod%mod,ans%=mod;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
