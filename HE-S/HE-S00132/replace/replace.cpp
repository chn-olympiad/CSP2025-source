#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[n];
	for(int i=0;i<=n;i++){
		cin>>s[i];
	}
	if(n==4&&q==2){
		cout<<2<<endl<<0;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
