#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
string s;
int n,k,ans,a[501];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	cout<<ans;
	return 0;
}
