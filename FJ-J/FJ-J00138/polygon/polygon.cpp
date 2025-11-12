/*
text 21-25
预计时间：1.3S
如来佛祖保佑我通过此题

       |  |  |
       |  |  |  
 |-----|--|--|----|
 |`````|``|``|````|
 |````````````````|
 ||||||||||||||||||
  
*/
#include<bits/stdc++.h>
using namespace std;
long long n,maxx;
long long a[5005];
long long dp[5005][4];
long long dpl[5005][4];
long long cnt[5005][4];
long long ans,mod=998244353;
long long sum[5005][5005];
bool cmp(long long x,long long y) {
	return x<y;
}
inline long long read() {
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch==45)f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void open(long long u,long long i) {
	for(long long j=maxx; j>=0; j--) {
		if(j+a[i]<=maxx) {
			dp[j+a[i]][u+1]+=dp[j][u];
			dp[j+a[i]][u+1]%=mod;
		} else {
			cnt[i][u+1]+=dp[j][u];
			cnt[i][u+1]%=mod;
		}
	}
}
inline void o3(long long i) {
	for(long long j=maxx; j>=0; j--) {
		if(j+a[i]<=maxx) {
			dp[j+a[i]][3]+=dp[j][3];
			dp[j+a[i]][3]%=mod;
		} else {
			cnt[i][3]+=dp[j][3];
			cnt[i][3]%=mod;
		}
	}
}
int main() {
//	freopen("polygon_check.in","r",stdin);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(long long i=1; i<=n; i++) {
		a[i]=read();
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	dp[a[1]][1]=1;
	dp[0][0]=1;
	cnt[1][0]=cnt[1][1]=cnt[1][2]=cnt[1][3]=0;
	for(long long i=2; i<=n; i++) {
		for(long long u=0; u<=3; u++)
			cnt[i][u]=cnt[i-1][u];
		for(long long u=0; u<=2; u++) {
			cnt[i][u+1]+=cnt[i-1][u];
		}
		cnt[i][3]+=cnt[i-1][3];
		o3(i);
		open(2,i);
		open(1,i);
		open(0,i);
		for(long long j=maxx; j>=0; j--) {
			sum[i][j]=sum[i][j+1]+dp[j][3]+dp[j][2];
			sum[i][j]=sum[i][j]%mod;
		}
	}
	for(long long k=1; k<=n; k++) {
		ans=ans+sum[k-1][a[k]+1]+cnt[k-1][3]+cnt[k-1][2];
		ans=ans%mod;
//		cout<<sum[k-1][a[k]+1]<<" "<<cnt[k-1][3]<<' '<<cnt[k-1][2]<<"\n";
	}
	cout<<ans;
	return 0;
}
