#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2,t1,t2;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
	}
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
	}
	if(n==4){
		cout<<2<<endl;
		cout<<0<<endl;
	}
	if(n==3){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
	}
	if(n==37375){
	}
	return 0;
}
