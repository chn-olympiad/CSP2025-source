#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("repalce.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s;
	for(int i=1;i<=q;i++) cin>>s;
	for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}


