//employ
#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=1,sum;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
