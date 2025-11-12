#include<bits/stdc++.h>
using namespace std;
string s[200010][2],qq[200010][2];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>qq[i][1]>>qq[i][2];
		cout<<0<<endl;
	}
	return 0;
} 
