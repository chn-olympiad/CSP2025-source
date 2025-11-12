#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353ll;
long long n,m,ans=1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
