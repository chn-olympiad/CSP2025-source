#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int mod=998244353;
int n,m,c[maxn],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=n;i>n-m;i--) ans*=n%mod;
	cout<<ans%mod;
	return 0;
}
