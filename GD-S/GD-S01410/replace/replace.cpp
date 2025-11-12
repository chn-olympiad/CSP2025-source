#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string s1[2*1e5+5],s2[2*1e5+5];
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	string s3,s4;
	while(q--){
		cin>>s3,s4;
		if(s3.size()!=s4.size()){
			cout<<0<<endl;
			continue;
		}
		else{
			cout<<2;
		}
	}
	return 0;
} 
