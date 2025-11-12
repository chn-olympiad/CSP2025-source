#include<bits/stdc++.h>
using namespace std;
namespace estidi{
	const int mod=998244353;
	int c[503];
	long long f[262147][21];
	int main(){
		int n,m,all1=1;
		string s;
		scanf("%d%d",&n,&m);
		cin>>s;
		s=" "+s;
		for(int i=1;i<s.size();i++)
			all1&=(s[i]=='1');
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
			all1&=(c[i]!=0);
		}
		if(all1){
			long long ans=1;
			for(int i=1;i<=n;i++)
				ans=ans*i%mod;
			printf("%lld",ans);
			return 0;
		}
		if(m==n){
			printf("0");
			return 0;
		}
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			int now=__builtin_popcount(i)+1;
			for(int j=1;j<=n;j++)
				if((i&(1<<(j-1)))==0){
					for(int k=0;k<=n;k++)
						if(s[now]=='1'&&now-1-k<c[j])
							f[i|(1<<(j-1))][k+1]=(f[i|(1<<(j-1))][k+1]+f[i][k])%mod;
						else
							f[i|(1<<(j-1))][k]=(f[i|(1<<(j-1))][k]+f[i][k])%mod;
				}
		}
		long long ans=0;
		for(int i=m;i<=n;i++)
			ans=(ans+f[(1<<n)-1][i])%mod;
		printf("%lld",ans);
		return 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	estidi::main();
	return 0;
}
