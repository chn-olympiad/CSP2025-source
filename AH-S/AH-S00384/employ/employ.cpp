#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[505],f=-1,pw[505],mod=998244353,ans;
string s;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	pw[0]=1;
	for(int i=1;i<=n;i++) {
		pw[i]=pw[i-1]*i;
		pw[i]%=mod;
	}
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++) {
		if(f==-1&&s[i]=='1') {
			f=i;
		}
	}
	//cout<<f<<endl;
	if(m==1) {
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) {
			//cout<<a[i]<<" "<<f<<endl;
			if(a[i]>f) {
				ans++;
			}
		}
		cout<<(ans*pw[n-1])%mod;
		//cout<<endl<<ans;
	}
	else {
		cout<<pw[n];
	}
	return 0;
}
/*
6 1
000100
1 2 3 4 5 6
*/
