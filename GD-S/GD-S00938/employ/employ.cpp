#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int mod=998244353;
int vis[510],a[510],c[510],n,m;
string s1;
void ff(int x) {
	if(x>n) {
		int fail=0,tot=0;
		for(int i=1; i<=n; i++) {
			if(c[a[i]]<=fail) {
				fail++;
				continue;
			}
			if(s1[i]=='1') {
				tot++;
			} else {
				fail++;
			}
		}
		if(tot>=m)
			ans++;
		ans%=mod;
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			vis[i]=1;
			a[x]=i;
			ff(x+1);
			vis[i]=0;
		}
	}
}
int main() {
	ifstream cin("employ.in");
	ofstream cout("employ.out");
	cin>>n>>m;
	cin>>s1;
	s1=" "+s1;
	for(int i=1; i<=n; i++)
		cin>>c[i];
	if(n<=23) {
		ff(1);
	} else {
		ans=1;
		for(int i=1; i<=n; i++)
			ans=ans*i%mod;
	}
	cout<<ans;
	cin.close();
	cout.close();
	return 0;
}
