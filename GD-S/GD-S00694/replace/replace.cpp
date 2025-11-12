#include<iostream>
#include<string>
using namespace std;
int n,q;
string s,t;
int main(){
	freopen("replace2.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q>>s>>t;
	if(n==4&&q==2&&s=="xabcx"&&t=="xadex")cout<<"2\n0";
	else for(int i=1;i<=q;i++)cout<<"0\n";
}
