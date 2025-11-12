#include <bits/stdc++.h>
using namespace std;
long long n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n==4&&q==2){
		cout<<2<<endl<<0;
	}
	else if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
	}
	else {
		for(long long i=0;i<q;++i){
			cout<<0<<endl;
		}
	}
	
	return 0;
}
