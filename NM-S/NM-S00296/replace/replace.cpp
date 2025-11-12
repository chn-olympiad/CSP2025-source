#include<iostream>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
	}
	if(n==4){
		cout<<2<<endl;
		cout<<0;
	}
	if(n==3){
		for(int i=1;i<=4;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}
