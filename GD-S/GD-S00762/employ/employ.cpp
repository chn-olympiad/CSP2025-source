#include<bits/stdc++.h>
using namespace std;
const int M=505;
const long long mod=998244353;
long long rd(){
	long long res=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0')res=res*10+c-'0',c=getchar();
	return res;
}
void wt(long long x){
	if(x>9)wt(x/10);
	putchar(x%10+'0');
}
int n,m,s[M],c[M],sm[M],pw[19];
long long jie[M],nijie[M],dp[262144][19];
long long fp(long long x,long long y){
	long long res=1;
	while(y){
		if(y%2==1)res=(res*x)%mod;
		x=(x*x)%mod,y/=2;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	pw[0]=1;
	for(int i=1;i<=18;++i)pw[i]=pw[i-1]*2;
	jie[0]=nijie[0]=1;
	for(int i=1;i<=500;++i){
		jie[i]=(jie[i-1]*i)%mod,nijie[i]=fp(jie[i],mod-2);
//		cout<<jie[i]<<' '<<nijie[i]<<endl;
	}
	char cc=getchar();
	for(int i=1;i<=n;++i){
		cc=getchar();
		s[i]=cc-'0';
	}
	for(int i=1;i<=n;++i)c[i]=rd(),sm[c[i]]++;
	for(int i=1;i<=n;++i)sm[i]=sm[i-1]+sm[i];
//	for(int i=1;i<=n;++i)cout<<s[i]<<' '<<c[i]<<endl;
	if(m==1){
		int sum=0;
		long long ans=1;
		for(int i=1;i<=n;++i){
			if(s[i]==0){
				sum++;
			}else{
//				cout<<"i="<<i<<' '<<sm[i-1]<<' '<<(i-sum-1)<<endl;
				ans=(ans*(sm[i-1]-(i-sum-1)))%mod;
			}
		}
		ans=(ans*jie[sum])%mod;
		printf("%lld",(jie[n]-ans+mod)%mod);
	}else if(m==n){
		if(sm[0]){
			printf("0");
		}else{
			printf("%lld",jie[n]);
		}
	}else{
		dp[0][0]=1;
//		int sum1=0;
		for(int i=0;i<=pw[n]-1;++i){
			int sb=0;
			for(int j=0;j<n;++j)if((pw[j]&i))sb++;
			for(int j=0;j<n;++j){
				if((pw[j]&i))continue; 
//				cout<<"DONE"<<" "<<(pw[j]|i)<<' '<<i<<" "<<j<<' '<<endl;
				for(int k=0;k<=sb;++k){
//					if(i<=4&&k<=3)cout<<i<<' '<<k<<' '<<dp[i][k]<<"DPIK"<<endl;
					if(s[sb+1]==0){
						dp[(pw[j]|i)][k]=(dp[(pw[j]|i)][k]+dp[i][k])%mod;
					}else{
						if(sb-k>=c[j+1])dp[(pw[j]|i)][k]=(dp[(pw[j]|i)][k]+dp[i][k])%mod;
						else{
							dp[(pw[j]|i)][k+1]=(dp[(pw[j]|i)][k+1]+dp[i][k])%mod;
						}
					}
				}
			}
		}
//		for(int j=0;j<=n;++j){
//			cout<<"DP["<<"]"<<j<<'='<<dp[pw[n]-1][j]<<endl;
//		}
		long long ans=0;
		for(int j=m;j<=n;++j)ans+=dp[pw[n]-1][j];
		printf("%lld",ans%mod);
	}
	return 0;
}


