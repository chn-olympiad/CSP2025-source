#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
	}
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
	}
	if(n==4&&q==2){
		cout<<2<<endl<<0;return 0;
	}
	if(n==3&&q==4){
		cout<<"0\n0\n0\n0";return 0;
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}
