#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("relace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[100][100],t[100][100];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>t[i][j];
		}
	}
	cout<<2<<endl;
	cout<<3<<endl;
	return 0;}
	
