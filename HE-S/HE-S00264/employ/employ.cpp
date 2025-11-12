#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(;m<=n;m++){
		for(int tmp=n-m+1;tmp<=n;tmp++){
			ans*=tmp;
			ans%=mod;
		}
	}
	cout<<ans;
}

