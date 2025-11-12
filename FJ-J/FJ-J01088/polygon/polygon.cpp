#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
#define N 5005
using namespace std;
int n,a[N],pre,ans;
const int MOD=998244353;
int dp[N*N];
int Qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res*=a,res%=MOD;
		b>>=1;
		a*=a,a%=MOD;
	}
	res%=MOD;
	return res;
}
void Spec_(){
	ans=(Qpow(2,n)-n-1-n*(n-1)/2+MOD)%MOD;
	cout<<ans;
}
int _01pack(int nn,int V){
	for(int i=0;i<=5003*5003;i++)
		dp[i]=0;
	dp[0]=1;
	for(int i=1;i<=nn;i++)
		for(int j=V;j>=a[i];j--)
			dp[j]+=dp[j-a[i]],dp[j]%=MOD;
	int res=0;
	for(int i=0;i<=V;i++)
		res+=dp[i],res%=MOD;
	int cnt=0;
	for(int i=1;i<=nn;i++)
		if(pre-a[i]<=V)
			cnt++;
	res=(res-cnt+MOD)%MOD;
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1){
		Spec_();
		return 0;
	}
	pre=a[1]+a[2];
	for(int i=3;i<=n;i++){
		int Del=max(pre-a[i]-1,-1LL);
		ans+=_01pack(i-1,Del);
		ans%=MOD;
		pre+=a[i]; 
	}
	cout<<ans;
	return 0;
}
