#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[s1]=s2;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(!s.count(t1)){
			puts("0");
		}
		if(s[t1]!=t2) puts("0");
		else puts("1");
	}
	return 0;
}

