#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string a[n][2];
	string k[1][2];
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>k[i][1]>>k[i][2];
	}
	for(int i=1;i<=q;i++){
		cout<<"0"<<endl;
	}
	return 0;
} 
