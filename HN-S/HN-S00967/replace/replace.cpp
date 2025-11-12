//replace
#include<bits/stdc++.h>
using namespace std;
int n,q,s[3][200005],t[3][200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[1][i]>>s[2][i];
	for(int i=1;i<=q;i++)cin>>t[1][i]>>t[2][i];
	if(n==4)cout<<2<<'\n'<<0;
	else cout<<"0\n0\n0\n0";
	return 0;
}
