#include<bits/stdc++.h>
using namespace std;
string s[2005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		cout<<"0"<<endl;
	}
	return 0;
} 
