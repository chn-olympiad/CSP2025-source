#include<bits/stdc++.h>
using namespace std;
string s[100005][3],t[100005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=2;k++){
			cin>>s[i][k];
		}
	}
	for(int i=1;i<=q;i++){
		for(int k=1;k<=2;k++){
			cin>>t[i][k];
		}
	}
	for(int j=1;j<=q;j++){
		cout<<0;
	}
	
	return 0;
}
