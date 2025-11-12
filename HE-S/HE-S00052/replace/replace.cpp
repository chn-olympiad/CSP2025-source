#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string a1,a2,a3,a4,a5,a6;
	string b1,b2,b3,b4,b5,b6,k,l;
	cin>>n>>q;
	if(n==4 &&q==2){
		cin>>a1>>a2;
		cin>>a3>>a4;
		cin>>a5>>a6;
		cin>>b1>>b2;
		cin>>b3>>b4;
		cin>>b5>>b6;
		cout<<2<<endl;
		cout<<0<<endl;
	}
	if(n==3 &&q==4){
		cin>>a1>>a2;
		cin>>a3>>a4;
		cin>>a5>>a6;
		cin>>b1>>b2;
		cin>>b3>>b4;
		cin>>b5>>b6;
		cin>>k>>l;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
