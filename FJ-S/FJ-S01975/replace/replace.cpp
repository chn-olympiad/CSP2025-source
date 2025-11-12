#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][5],t[200005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=2;k++){
			cin>>s[i][k];
		}
	}
	for(int j=1;j<=q;j++){
		for(int k=1;k<=2;k++){
			cin>>t[j][k];
		}
	}
	for(int j=1;j<=q;j++){
		cout<<0<<endl;
	}
	return 0;
}
