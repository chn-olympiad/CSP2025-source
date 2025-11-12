#include<bits/stdc++.h>
#define md 998244353
using namespace std;
int n,m;
int s[505],c[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	int ans=1;
	for(int i=n;i>=1;i--) {
		ans*=i;
		ans%=md;
	}
	cout<<ans;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
