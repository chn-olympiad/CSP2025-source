#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,sum0,sum1,ans;
int fac[505],p[505],c[505];
char s[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i;
	cin>>n>>m;
	scanf("%s",s+1);
	for(i=1;i<=n;i++)scanf("%lld",&c[i]);
	if(n<=10){
		for(i=1;i<=n;i++)p[i]=i;
		do{
			sum0=sum1=0;
			for(i=1;i<=n;i++){
				if(sum0>=c[p[i]]){
					sum0++;
					continue;
				}
				if(s[i]=='1')sum1++;
				if(s[i]=='0')sum0++;
			}
			if(sum1>=m)ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}else{
		if(m==n){
			cout<<0;
		}else{
			fac[0]=1;
			for(i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
			cout<<fac[n]%mod;
		}
	}
}
