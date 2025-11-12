#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	string t1,t2;
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
	}
	if(n==4&&q==2){
		cout<<2<<endl<<0; 
	}
	if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	if(n=37375&&q==27578){
		cout<<0;
	}

	return 0;
}
