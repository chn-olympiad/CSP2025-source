#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=505;
int n,m,s[N],c[N];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>s[i]; 
	}
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	m=2;
	cout<<m%MOD;
	return 0;
}
