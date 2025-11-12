#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000066663
#define p 191
#define len 202000
int qpow(int a, int b) {
	int ans=1;
	while(b) {
		if (b&1) ans=ans*a%mod;
		a=a*a%mod, b>>=1;
	}
	return ans;
}
int jc[1010000];
int n, q, x[len], y[len], d[len], hsh1[1010000], hsh2[1010000], ans, ln[len];
string a, b;
map <int, int> mp;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>a>>b, ln[i]=a.length();
		for(int j=0;j<a.length();j++) x[i]=(x[i]*p+a[j]-'a')%mod;
		for(int j=0;j<b.length();j++) y[i]=(y[i]*p+b[j]-'a')%mod;
		d[i]=((y[i]-x[i])%mod+mod)%mod;
	}
	jc[0]=1;
	int t=1;
	for(int i=1;i<1010000;i++) jc[i]=jc[i-1]*p%mod, mp[t]=i, t=t*p%mod;
	while(q--) {
		cin>>a>>b;
		for(int j=0;j<a.length();j++) hsh1[j+1]=(hsh1[j]*p+a[j]-'a')%mod;
		for(int j=0;j<b.length();j++) hsh2[j+1]=(hsh2[j]*p+b[j]-'a')%mod;
		ans=0;
		for(int i=1;i<=n;i++) {
			int tmp=(hsh2[a.length()]-hsh1[b.length()]+mod)%mod;
			if(mp[tmp*qpow(d[i], mod-2)%mod]) {
				tmp=mp[tmp*qpow(d[i], mod-2)%mod]-1;
				int r=a.length()-tmp;
				int l=r-ln[i]+1;
				if(l<1) continue;
				if((hsh1[r]-hsh1[l-1]*jc[ln[i]]%mod+mod)%mod==x[i])
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
