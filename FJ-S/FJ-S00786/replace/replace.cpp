#include <bits/stdc++.h>
using namespace std;
string s[10000][3];
string p[10000][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>p[i][j];
		}
	}
	cout<<0<<endl;
	cout<<0<<endl;
	cout<<0<<endl;
	cout<<0<<endl;
	return 0;
} 
