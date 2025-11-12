#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll k;
ll b[1005];
ll bk[1005];
ll bok[1005];
/*
ll yh(ll x,ll y){
	ll g[20];
	ll h[20];
	ll as[20];
	ll d=0;
	while(x>0){
		g[++d]=x%2;
		x/=2;
	}ll de=0;
	while(y>0){
		h[++de]=y%2;
		y/=2;
	}for(ll i=1;i<=20;i++){
		if(g[i]!=h[i]){
			as[i]=1;
		}else{
			as[i]=0;
		}
	}ll cnt=0;
	for(ll i=20;i>=1;i--){
		if(as[i]==1){
			cnt+=as[i];
		}cnt*=2;
	}return cnt;
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	ll fflag=1;
	ll flagg=1;
	for(ll i=1;i<=n;i++){
		ll a;
		scanf("%lld",&a);
		b[i]=a;
		if(a!=1){
			fflag=0;
		}if(a!=1 && a!=0){
			flagg=0;
		}
		/*
		ll j=1;
		while(a>0){
			b[i][j]=a%2;
			a/=2;
			j++;
		}*/
		bk[i]=a^k;
	}if(flagg){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			if(b[i]%2==1){
				ans++;
			}
		}cout<<ans;
		return 0;
	}if(fflag){
		cout<<n/2;
		return 0;
	}ll ans=0;
	for(ll len=1;len<=n;len++){
		for(ll l=1;l<=n-len+1;l++){
			ll r=l+len-1;
			ll cnt=0;
			ll flag=1;
			for(ll i=l;i<=r;i++){
				cnt^=bk[i];
				if(bok[i]==1){
					flag=0;
					break;
				}
			}if(flag){
				if(cnt==k){
					ans++;
					cout<<l<<' '<<r<<endl;
					bk[l]=1;
					bk[r]=1;
				}
			}
		}
	}cout<<ans;
	return 0;
}
