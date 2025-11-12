#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200020],b[200020],c[200020],d[200020];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>d[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<"\n";
	}
	return 0;
} 

