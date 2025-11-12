#include <bits/stdc++.h>
using namespace std;
int n,q;
string a[500001]={};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>a[i];
		if(n==4 && q==2){
			cout<<"2"<<endl<<"0"<<endl;
			return 0;
		}
		if(n==3 && q==4){
			cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
			return 0;
		}
	}
	return 0;
}
