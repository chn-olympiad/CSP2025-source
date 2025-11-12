#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[100005];
ll ans=0;
ll mod=998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll maxn=(1<<n)-1;
	for(ll i=0;i<=maxn;i++){
		ll temp=i,cnt=0,sum=0,maxx=0;
		for(int j=1;j<=n;j++){
			if(temp%2==1){
				cnt++;
				sum+=a[j];
				maxx=max(maxx,a[j]);
			}
			temp/=2;
		}
		if(cnt>=3 and sum>maxx*2) ans=(ans+1)%mod;
	}
	cout<<ans;
	return 0;
}

