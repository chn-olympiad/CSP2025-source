#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
char a[505];
int c[505];
int p[505],ans;
int fac=1;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) fac=fac*i%998244353;
	bool flag=true;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]=='0') flag=false;
	}
	if(flag) {
		cout<<fac;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	do{
		int tot=0,sum=0;
//		for(int i=1;i<=n;i++) cout<<p[i];
//		cout<<endl;
		for(int i=1;i<=n;i++) {
			//p[i]
//			cout<<tot<<" ";
			if(tot<c[p[i]] && a[i]=='1') {
				sum++;
			}
			else tot++;
		}
//		cout<<endl;
		if(sum>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
