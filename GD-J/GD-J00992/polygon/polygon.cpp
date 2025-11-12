#include<bits/stdc++.h>//RP++
using namespace std;//RP++
#define int long long//RP++
const int mod=998244353;//RP++
const int N=5005;//RP++
int n,a[N];//RP++
int f[N][N],sum[N];//RP++
//RP++
int qpow(int n,int k){//RP++
	int ans=1;//RP++
	while(k!=0){//RP++
		if(k&1) ans=ans*n%mod;//RP++
		n=n*n%mod;//RP++
		k>>=1;//RP++
	}//RP++
	return ans;//RP++
}//RP++
//RP++
signed main(){//RP++
	freopen("polygon.in","r",stdin);//RP++
	freopen("polygon.out","w",stdout);//RP++
	ios::sync_with_stdio(false);//RP++
	cin.tie(0);//RP++
	cout.tie(0);//RP++
	cin>>n;//RP++
	for(int i=1;i<=n;i++)//RP++
		cin>>a[i];//RP++
	sort(a+1,a+n+1);//RP++
	if(a[n]==1){//RP++
		cout<<(qpow(2,n)-(n*(n-1)/2)%mod-n-1+mod)%mod;//RP++
		return 0;//RP++
	}//RP++
	sum[0]=0;//RP++
	for(int i=1;i<=n;i++){//RP++
		sum[i]=sum[i-1]+a[i];//RP++
	}//RP++
	f[0][0]=1;//RP++
	for(int i=1;i<=n;i++){//RP++
		for(int j=0;j<a[i];j++){//RP++
			f[i][j]=f[i-1][j];//RP++
		}//RP++
		for(int j=a[i];j<=sum[i];j++){//RP++
			f[i][j]=f[i-1][j]+f[i-1][j-a[i]];//RP++
		}//RP++
	}//RP++
	int ans=0;//RP++
	for(int i=3;i<=n;i++){//RP++
		for(int j=1;j<=max(0ll,sum[i-1]-a[i]-1);j++){//RP++
			ans+=f[i][j];//RP++
		}//RP++
		ans+=(sum[i-1]>a[i]);//RP++
	}//RP++
	cout<<ans;//RP++
	return 0;//RP++
} //RP++
