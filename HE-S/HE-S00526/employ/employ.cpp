#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int n,m,ans=1;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--)
		ans=(ans*i)%mod;
	cout<<ans;
	return 0;
}
