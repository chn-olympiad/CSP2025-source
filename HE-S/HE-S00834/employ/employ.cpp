#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m;
int a[550],c[550];
int ans=1;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=int(c)-'a';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++) ans*=i%mod;
	for(int i=1;i<=m;i++) ans*=i%mod;
	for(int i=1;i<=n+m;i++) ans/=i%mod;
	cout<<ans;
	return 0;
}
