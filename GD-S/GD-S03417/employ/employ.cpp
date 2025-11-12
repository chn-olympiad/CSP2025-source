#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	ll ans=1;
	for(int i=2;i<=n;i++) ans=ans*i%mod;
	cout<<ans;
	return 0;
}
