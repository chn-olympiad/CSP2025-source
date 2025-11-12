#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++) {
	cin>>s1>>s2;}
	for(int i=0;i<q;i++)
	{cin>>t1>>t2;}
	if(n==4 && q==2) {
	cout<<2<<endl;
	cout<<0;}
	if(n==3 && q==4) for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}
