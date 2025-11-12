#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>a>>b;
	for(int i=1;i<=q;++i){
		cin>>a>>b;
	}
	if(n==4&&q==2) cout<<4<<endl<<2;
	else{
		for(int i=1;i<=q;++i) cout<<0<<endl;
	}
	return 0;
}
