#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010;
const ll M=2e6+10;
const ll MOD=998244353;
ll n,a[N],ans,c[N],d[N],dp[210][110];
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
ll f(ll a,ll b){
	ll ret=1,tmp=a;
	while(b){
		if(b%2) ret=ret*tmp%MOD;
		tmp=tmp*tmp%MOD;
		b/=2;
	}
	return ret;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	if(n<=20){
		for(ll s=1;s<=(1<<n)-1;s++){
			ll sum=0,zdz=0,cnt=0;
			for(ll i=20;i>=0;i--){
				if((s>>i)&1){
					zdz=max(zdz,a[i+1]);
					sum=sum+a[i+1];
					cnt++;
				}
			}
			if(cnt>=3 && sum>(zdz*2)) ans++;
		}
		cout<<ans;
	}
	else{
		ll maxx=0;
		for(ll i=1;i<=n;i++) maxx=max(maxx,a[i]);
		if(maxx==1){
			c[0]=1;
			for(ll i=1;i<=n;i++) c[i]=c[i-1]*i%MOD;
			d[n]=f(c[n],MOD-2ll);
			for(ll i=n-1;i>=0;i--) d[i]=d[i+1]*(i+1)%MOD;
			for(ll i=3;i<=n;i++){
//				cout<<c[n]<<" "<<d[n-i]<<" "<<d[i]<<endl;
				ans=(ans+c[n]*d[n-i]%MOD*d[i]%MOD)%MOD;
			}
			cout<<ans;
		} 
		else{
			dp[0][0]=1;
			for(ll i=1;i<=n;i++){
				for(ll j=0;j<=2*maxx+1;j++){
					for(ll k=0;k<=maxx;k++){
						if(j+a[i]>(2*maxx)) dp[2*maxx+1][max(k,a[i])]=(dp[2*maxx+1][max(k,a[i])]+dp[j][k])%MOD;
						else{
							dp[j+a[i]][max(k,a[i])]=(dp[j+a[i]][max(k,a[i])]+dp[j][k])%MOD;
						}
					}
				}
			}	
			for(ll i=1;i<=2*maxx+1;i++){
				for(ll j=1;j<=maxx;j++){
					if(i>(2*j)){
						ans=(ans+dp[i][j])%MOD;
					}
				}
			} 
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					if(a[i]+a[j]>(2*max(a[i],a[j]))) ans--;
				}
			}
			ans=(ans+MOD)%MOD;
			cout<<ans;
		}
	}
	return 0;
}
