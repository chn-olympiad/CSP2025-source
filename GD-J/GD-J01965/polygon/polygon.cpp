#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;
const int N=5e3+5;

int n;
int a[N];

ll dp[N][2];

int cnt,f[N];
void wk(int k){
	if(k>n){
		int s=0,ma=0;
		for(int i=1;i<=n;i++)
			if(f[i]){
				s+=a[i];
				ma=max(ma,a[i]);
			}
		if(s>2*ma)
			cnt++;
		return;
	}
	f[k]=0;
	wk(k+1);
	f[k]=1;
	wk(k+1);
}
ll ksm(ll a,ll p){
	ll res=1;
	while(p){
		if(p&1)
			res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
ll ft[N],ftt[N];
void init(){
	ft[0]=1;
	for(int i=1;i<N;i++)
		ft[i]=ft[i-1]*i%mod;
	ftt[N-1]=ksm(ft[N-1],mod-2);
	for(int j=N-2;j>=0;j--)
		ftt[j]=ftt[j+1]*(j+1)%mod;
	return;
} 
ll C(int a,int b){
	ll ans=ft[a]*ftt[b]%mod*ftt[a-b]%mod;
	return ans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	scanf("%d",&n);
	int ma=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ma=max(ma,a[i]);
	}
	
	if(n<=20){
		wk(1);
		printf("%d",cnt);
		return 0;
	}
	if(ma==1){
		ll ans=0;
		init();
		for(int i=3;i<=n;i++)
			ans=(ans+C(n,i))%mod;
		printf("%lld",ans);
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
		for(int j=1;j<i;j++)
			if(a[i]>a[j])
				dp[i][1]=(dp[i][1]+dp[j][1])%mod;
	}
	ll res=(dp[n][0]+dp[n][1])%mod;
	printf("%lld",res);
	return 0;
}
