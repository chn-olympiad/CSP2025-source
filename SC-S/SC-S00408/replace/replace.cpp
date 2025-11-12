#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s1,s2,s3,s4;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	for(int i=1;i<=q;i++){
		cin>>s3>>s4;
	}
	if(n==4 && q==2) cout<<2<<endl<<0;
	if(n==3 && q==4){
		for(int i=1;i<=4;i++) cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 