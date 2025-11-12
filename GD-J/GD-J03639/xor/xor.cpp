#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,n,k,t=1,m,a[500010];
map<ll,ll>bj;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		m^=a[i];
		if(m==k||bj[k^m]==t){
			m=0;
			ans++;
			t++;
		}else bj[m]=t;
	}
	cout<<ans;
	return 0;
}
