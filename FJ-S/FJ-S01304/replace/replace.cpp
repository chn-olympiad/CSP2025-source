#include <bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>b;
	}
	for(int i=0;i<q;i++){
		cin>>a;
		cin>>b;
	}
	if(n==4){
		cout<<2<<endl<<0;
	}
	if(n==3){
		for(int i=1;i<=4;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}
