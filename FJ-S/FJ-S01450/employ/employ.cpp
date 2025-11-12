#include<bits/stdc++.h>
#define ll long long
#define db double
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define mkp make_pair
#define il inline
#define endl "\n"
const ll mod=998244353;
const ll inf=1e18;
using namespace std;
ll n,m,a[505],b[505],c[505],ans=0;string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++) b[i]=i;
	do{
		ll rt=0;
		for(ll i=1;i<=n;i++) c[i]=a[b[i]];
//		for(ll i=1;i<=n;i++) cout<<c[i]<<" ";
//		cout<<endl; 
		for(ll i=1;i<=n;i++){
			if(rt>=c[i]){
				rt++; continue;
			}
			if(s[i]=='0'){
				rt++;
			}
		} 
		if((n-rt)>=m) ans++,ans%=mod;
	}while(next_permutation(b+1,b+n+1));
	cout<<ans<<endl;
	return 0;
}

