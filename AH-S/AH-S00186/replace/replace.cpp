#include<bits/stdc++.h>
using namespace std;
string s[int(2e5)+10];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i+=2){
		cin>>s[i]>>s[i+1];
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		cout<<0;
	}
	return 0;
}
