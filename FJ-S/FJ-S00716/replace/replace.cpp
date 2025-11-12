#include<bits/stdc++.h>
using namespace std;
string s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	map<string,string> mp;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[i]=s1;
		mp[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;	
		cout<<0<<endl;
	}
}
