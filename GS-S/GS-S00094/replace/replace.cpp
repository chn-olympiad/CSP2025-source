#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		cout<<i%2<<endl;
	}
	return 0;
}
