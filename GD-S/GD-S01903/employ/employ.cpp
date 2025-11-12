#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353;
#define int long long
int n,m,c[N],p[N],ans;
string s;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) {
		for(int i=1;i<=n;i++) p[i]=i;
		do {
			int no=0,tt=0;
			for(int i=1;i<=n;i++) {
				if(no>=c[p[i]]||s[i]=='0') no++;
				else {
					tt++;
					no=0;
				}
			}
//			for(int i=1;i<=n;i++) cout<<p[i]<<" ";
//			cout<<endl;
			if(tt>=m) {
				ans++;
			}
		} while(next_permutation(p+1,p+1+n));
		cout<<ans;
	} else {
		if(m==n) {
			bool fl=1;
			for(int i=1;i<=n;i++) {
				if(s[i]=='0'||c[i]==0) fl=0;
			}
			if(fl) {
				int ans=1;
				for(int i=1;i<=n;i++) ans=ans*i%mod;
				cout<<ans;
			} else cout<<0;
		} else cout<<0;
	}
	return 0;
} 
