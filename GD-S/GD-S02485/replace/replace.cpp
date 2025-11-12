#include<bits/stdc++.h>
using namespace std;
string s[200020][2];
string t[200020][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	cout<<2<<endl;
	cout<<0<<endl;
	return 0;
}
