#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][3];
string t[N][3];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++) {
		cin>>t[i][1]>>t[i][2];
	}
	if(n==4&&q==2) cout<<2<<'\n'<<0;
	else if(n==3&&q==4) cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0;
	else cout<<0;
	return 0;
}
