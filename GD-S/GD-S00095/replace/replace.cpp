#include<bits/stdc++.h>
using namespace std;
int n,q,s[200010][3],t[200010][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int j=1;j<=q;j++){
		cin>>t[j][1]>>t[j][2];
	}
	for(int i=1;i<=q;i++)
		cout<<0<<endl;
	return 0;
}
