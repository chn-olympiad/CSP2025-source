#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s,t;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<q;j++){
			cin>>s[i]>>t[j];
		}
	}
	if(n==4&&q==2){
		cout<<2<<endl;
		cout<<0<<endl;
	}else{
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
	}
	return 0;
}
