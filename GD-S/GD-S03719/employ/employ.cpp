#include<bits/stdc++.h>
using namespace std;

const int N=1e3+3;
const long long mod=998244353;
long long f[N];

void pre(){
	f[0]=1;
	for(int i=1;i<=N-3;i++){
		f[i]=f[i-1]*i%mod;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//pre();
	int n,m;
	cin>>n>>m;
	long long ans=1;
	for(int i=n-m+1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}

