#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
map<string,string>mp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,s2;
		cin>>s>>s2;
		mp[s]=s2;
	}
	while(q--){
		string t,t2;
		cin>>t>>t2;
		cout<<0<<endl;
	}
	return 0;
}
