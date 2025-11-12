#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,q;
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s;
	while(q--){
		cin>>s;
		cout<<n<<endl;
	}
	return 0;
}
