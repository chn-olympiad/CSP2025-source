#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
ll m,n;
string str;
ll c[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ans=ans*c[i]%M;
	}
	cout<<ans;
	return 0;
}
