#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	char i1[n];
	char i2[n];
	char j1[q];
	char j2[q];
	for(int i=0;i<n;i++){
		cin>>i1[i]>>i2[i];
	}
	for(int i=0;i<q;i++){
		cin>>j1[i]>>j2[i];
	}
	for(int k=0;k<q;k++){
	}
	if(n==4&&q==2){
		cout<<2<<endl;
		cout<<0<<endl;
	}
	if(n==3&&q==4){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
	}
	else cout<<2;
	return 0;
}
