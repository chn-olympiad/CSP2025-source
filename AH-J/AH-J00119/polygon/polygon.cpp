#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
#define N (int)(5e3+5)
using namespace std;
int a[N],ans,n,k;
int sum[N];
int dp[N][N];
inline void read(int &num);
inline void solve();
inline void solve2();
inline int getval(int l,int r);
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
inline void read(int &num){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		f=(ch=='-')?-1:1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	num=x*f;
}
inline void solve(){
	read(n);
	bool flag=true;
	for(int i=1;i<=n;++i){
		read(a[i]);
		if(a[i]!=1)flag=false;
	}
	if(flag){
		n-=2;
		printf("%lld\n",(1+n)*n/2);
		return ;
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(a[1]+a[2]>a[3]){
			puts("1");
		}else{
			puts("0");
		}
		return ;
	}
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		dp[1][i]=(sum[i]>a[i]*2)?1:0;
	}
	for(int i=1;i<=n-2;++i){
		dp[i][i+2]+=(sum[i+2]-sum[i-1]>a[i+2]*2)?1:0;
	}
	for(int step=2;step<=n-2;++step){
		for(int l=1;l<=n-step;++l){
			int r=l+step;
			if(sum[r]-sum[l-1]>a[r]*2){
				dp[l][r]++;
			}
			for(int k=l;k<r;++k){
				dp[l][r]+=max(dp[l][k]+dp[k+1][r],dp[l][k-1]+dp[k][r]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,dp[1][i]);
	}
	printf("%lld\n",ans%MOD);
}
