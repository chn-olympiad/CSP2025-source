#include<bits/stdc++.h>
#define N 507
#define mod 998244353
#define ll long long 

using namespace std;

int n,m,a[N],c[N],p[N],b[N],cnt[N],s[N];
char str[N];
ll fac[N];

int main()
{
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	scanf("%d%d%s",&n,&m,str+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=10){
		iota(p+1,p+n+1,1);
		int ans=0;
		while(1){
			for(int i=1;i<=n;i++) b[i]=c[p[i]];
			int cnt=0;
			for(int i=1;i<=n;i++) if(str[i]=='0'||cnt>=b[i]) cnt++;
			if(n-cnt>=m) ans++;
			if(!next_permutation(p+1,p+n+1)) break;
		}
		printf("%d\n",ans);
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++) if(str[i]=='0'||c[i]==0) return puts("0"),0;
		ll ans=1;
		for(int i=1;i<=n;i++) (ans*=i)%=mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) cnt[c[i]]++;
		s[0]=cnt[0];
		for(int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
		ll ans=0;
		for(int i=1;i<=n;i++) if(str[i]=='1'){
			int tmp=0,t2=0;
			ll prod=1;
			for(int j=1;j<i;j++){
				if(str[j]=='1'){
					(prod*=s[tmp]-t2)%=mod;
					t2++;
				} 
				else tmp++;
			}
			(prod*=s[n]-s[t2])%=mod;
			(prod*=fac[n-t2-1])%=mod;
			(ans+=prod)%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
