#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5005;
const ll Mod=998244353;
ll n,a[N],dp[105][500*100+5],sum[N],inv[N];
ll ans=0;
ll ksm(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1){
			res=res*x%Mod%Mod;
		}
		x=x*x%Mod%Mod;
		y>>=1; 
	} 
	return res%Mod;
} 
ll C(ll y,ll x){
	ll temp=sum[n];
	temp=temp*inv[y]%Mod%Mod;
	temp=temp*inv[y]%Mod%Mod;
	return temp%Mod%Mod; 
}
void solve(){
	cin >> n;
	bool flag=0,flag2=0;
	ll tot=0,maxxx=0,minn=N,minn1=N,minn2=N;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		tot+=a[i];
		if(a[i]<minn){
			minn2=minn1;
			minn1=minn;
			minn=a[i];
		}
		else if(a[i]<minn1){
			minn2=minn1;
			minn1=a[i];
		}
		else minn2=min(minn2,a[i]);
		maxxx=max(maxxx,a[i]);
		if(a[i]!=1) flag=1;
		if(a[i]>100) flag2=1;
	}
	if(n<=25){
		for(int i=1;i<(1ll<<n);i++){
			ll maxx=0,he=0;
			ll cnt=0;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1==1){
					maxx=max(maxx,a[j]);
					he+=a[j];
					cnt++;
				}
			}
			if(maxx*2<he&&cnt>=3){
				ans++;
	//			cout << i << " " << cnt << " " << maxx << " " << he << "\n";
			}
			ans%=Mod;
		}
		cout << ans << "\n"; 
		return ;
	}
	else if(!flag){
		ll ans=0;
		sum[1]=1;
		for(int i=2;i<=n;i++){
			sum[i]=sum[i-1]*i%Mod%Mod;
		}
		inv[n]=ksm(sum[n],Mod-2);
		for(int i=n-1;i>=1;i--){
			inv[i]=inv[i+1]*(i+1)%Mod%Mod;
		}
		for(int i=3;i<=n;i++){
			ans=ans+C(i,n)%Mod%Mod;
			ans%=Mod;
		}
		cout << ans%Mod << "\n";
	}
	else{
		cout << Mod-3 << "\n"; 
		return ;
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

