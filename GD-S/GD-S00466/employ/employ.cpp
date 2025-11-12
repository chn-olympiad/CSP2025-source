#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[510];
string s;
long long ans[5100];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	ans[0]=1;
	for(int i=1;i<=n;i++)ans[i]=1ll*ans[i-1]*i%mod;
	cout<<ans[n]%mod;
	return 0;
}

