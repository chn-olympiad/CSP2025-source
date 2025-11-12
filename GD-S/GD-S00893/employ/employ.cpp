#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e3+5;
int n,m,s[N],c[N],mod=998244353,ans=1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) ans=(ans*i)%mod;
	cout<<ans%mod;
	return 0;
}
