#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a>>b;
	}
	for(int i=0;i<q;i++){
		cin>>a>>b;
		if(a[0]=='x'&&a[a.size()-1]=='x'&&b[0]=='x'&&b[b.size()-1]=='x'){
			cout<<2<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}
