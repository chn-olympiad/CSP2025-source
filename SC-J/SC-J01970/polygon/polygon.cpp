#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005,mod=998'244'353;
ll n,a[N];
ll ans,f[2][N][2],s[2][N];
//前i个数组成的和=j的方案数,后面的0表示只有一个数,1表示至少有2个数
//方案数的前缀和,即前i个数组成的和<=j的方案数
ll qpow(ll a,ll b){
	ll res=1;
	while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	f[1][a[1]][0]=1;
	for(int i=2;i<n;i++){
		int cur=i&1,lst=cur^1;
		for(int j=0;j<=5000;j++){
			f[cur][j][0]=f[cur][j][1]=0;
			f[cur][j][0]=f[lst][j][0];
			f[cur][j][1]=f[lst][j][1];
			if(j>=a[i])
				f[cur][j][1]+=f[lst][j-a[i]][0]+f[lst][j-a[i]][1];
			if(j==a[i])f[cur][j][0]++;
			f[cur][j][0]%=mod;f[cur][j][1]%=mod;
//			printf("%d %d %lld\n",i,j,f[cur][j][1]);
			if(j==0)s[cur][j]=f[cur][j][1];
			else s[cur][j]=(s[cur][j-1]+f[cur][j][1])%mod;
		}
		int zg=(qpow(2ll,i)+mod-i-1-s[cur][a[i+1]])%mod;
		ans+=zg;ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5
1 2 3 4 5
*/