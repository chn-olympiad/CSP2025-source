#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5050;
const int mod=998244353;
int n,ans,a[N],v[N];
bool b[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		int maxlen=max(max(a[1],a[2]),a[3]);
		if(sum>2*maxlen) ans++;
	}
	cout<<ans%mod;
	return 0;
}