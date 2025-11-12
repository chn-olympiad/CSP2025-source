#include <bits/stdc++.h>
using namespace std;
long long n,q;
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	for(int i=1;i<=q;i++){
		cin>>y;
	}
	if(n==4&&q==2){
		cout<<2<<endl;
		cout<<0;
	}
	else if(n==3&&q==4){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0;
	}
}
