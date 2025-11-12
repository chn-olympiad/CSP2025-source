#include<bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mod 998244353
#define int long long
using namespace std;

const int N=1e5+30;
int n,m;
string str;
int c[N];
signed main(){
	file(employ);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	unsigned int ans=1;
	for(int i=2;i<=n;i++){
		ans*=i,ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}

