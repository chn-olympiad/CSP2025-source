#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		m[x]=y;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(m[s1]==s2) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
