#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;

long long n,a[5001],m,b[5001],ret,sum,ans;
long long inv[5001],fac[5001],ifac[5001];

void solve(){
	inv[1]=fac[1]=ifac[1]=1;
	inv[0]=fac[0]=ifac[0]=1;
	for(long long i=2;i<=n;i++){
		inv[i]=1ll*(p-p/i)*inv[p%i]%p;
		fac[i]=1ll*fac[i-1]*i%p;
		ifac[i]=1ll*ifac[i-1]*inv[i]%p;
	}
	return;
}

long long c(long long r,long long k){
	return 1ll*((fac[k]*ifac[r])%p)*ifac[k-r]%p;
}

void dfs(long long step,long long cnt){
	if(step==n){
		ret=0,sum=0;
		if(cnt>=3){
			for(long long i=1;i<=cnt;i++){
				sum+=b[i];
				ret=max(ret,b[i]);
			}
			if(sum>2*ret) ans++;
		}
		return;
	}
	dfs(step+1,cnt);
	b[cnt+1]=a[step+1];
	dfs(step+1,cnt+1);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i],m=max(m,a[i]);
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*m) cout<<1;
		else cout<<0;
		return 0;
	}
	if(m==1){
		solve();
		for(long long i=3;i<=n;i++){
			ans=c(i,n)+ans%p;
		}
		cout<<ans;
		return 0;
	}
	
    dfs(0,0);
    cout<<ans;
	
	return 0;
}
