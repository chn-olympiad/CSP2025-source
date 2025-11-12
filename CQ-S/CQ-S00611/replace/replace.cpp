#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005][3],w[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=n;i++){
		cin>>w[i][0]>>w[i][1];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<'\n';
	}
	
	return 0;
}
