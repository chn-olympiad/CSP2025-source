#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){
	char ch;
	int sum=0,x=1;
	ch=getchar();
	while(ch<'0'||(ch>'9')){
		if(ch=='-')x=-1;
		ch=getchar(); 
	}
	while((ch>='0')&&(ch<='9')){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*x;
}
//zzzzzz
int n,a[7777],sum[7777],dp[25000100],ans,xk;
const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=sum[i-1];j++){
			ans=(ans+dp[j])%mod;
		}
		for(int j=sum[i];j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
}
