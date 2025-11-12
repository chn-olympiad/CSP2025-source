#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,cnt,ans=1;
string a;
int b[503];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i])cnt++;
	}
	for(int i=1;i<=cnt;i++){
		ans=(ans%mod)*(i%mod)%mod;
	}
	cout<<ans;
	return 0;
}
