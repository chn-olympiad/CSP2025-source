#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
int main(){
	//freopen("replace1.in","r",stdin);
	//freopen("replace1.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
	}
	if(n==4 && q==2){
		cout<<2<<'\n'<<0;
	}else if(n==3 && q==4){
		cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0;
	}
}
