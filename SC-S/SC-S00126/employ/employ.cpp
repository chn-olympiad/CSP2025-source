#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int x;
	cin>>x;
	for(int i=1;i<=n;i++){
		int x1;
		cin>>x1;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}