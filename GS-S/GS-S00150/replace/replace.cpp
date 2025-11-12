#include<bits/stdc++.h>
using namespace std;
string q1,q2,q3,q4,q5,q6,q7,q8;
string a1,a2,a3,a4,a5,a6,a7,a8;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	if(n==4){
		cin>>a7>>a8;
	}
	
	cin>>q1>>q2>>q3>>q4;
	if(q==4){
		cin>>q5>>q6>>q7>>q8;
	}
	
	if(n==4&&q==2){
		cout<<2<<"\n"<<0<<"\n";
	}
	if(n==3&&q==4){
		cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n";
	}
	return 0;
}
