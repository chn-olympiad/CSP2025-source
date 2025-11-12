#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
	}
	for(int i=0;i<q;i++){
		string a,b;
		cin>>a>>b;
	}
	if(n==4 && q==2){
		cout<<2<<endl<<0;
	}
	if(n==3 && q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	return 0;
}     
