#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=1e5+1013;
ll t;


struct Club{
	ll m1,m2,m3;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
		}

		ll ans=0;

		for(ll i=1;i<=n;i++){
			ans+=max(max(a[i].m1,a[i].m2),a[i].m3);
		}

		cout<<ans<<'\n';
	}

	return 0;
}



//我想进迷惑行为大赏

