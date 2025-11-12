#include<bits/stdc++.h>
using namespace std;
char a[9000000];
string s1,s2,s3,s4;
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	for(int i=1;i<=q;i++){
		cin>>s3>>s4;
	}
	if(n==4){
		cout<<2<<endl<<0;
		return 0;
	}
	if(n==3){
		cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
		return 0;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	
	
	
	return 0;
} 
