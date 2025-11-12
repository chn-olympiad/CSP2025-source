#include<iostream>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s;
	string t;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int j=1;j<=q;j++){
		cin>>t[j][1]>>t[j][2];
		cout<<s[i][2]-s[i][1]<<endl<<t[j][2]-t[j][1];
	}
	return 0;
}
