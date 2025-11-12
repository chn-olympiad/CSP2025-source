#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll Mod=998244353;
const int N=5005;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(flag){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=Mod;
		}
		ans--;
		ans=((ans-n)%Mod+Mod)%Mod;
		ans=((ans-n*(n-1)/2)%Mod+Mod)%Mod;
		cout<<ans<<"\n";
		return 0;
	}else{
		int ans=0;
		for(ll s=0;s<(1<<n);s++){
			int maxa=0;
			int suma=0;
			for(int i=1;i<=n;i++){
				int app=(s>>(i-1ll))&1ll;
				maxa=max(maxa,app*a[i]);
				suma+=app*a[i];
			}
			if(suma>2*maxa){
				ans++;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
}
