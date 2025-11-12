#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll ans=1,n,m;cin>>n>>m;
	string a;cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans<<endl;
	return 0;
}
