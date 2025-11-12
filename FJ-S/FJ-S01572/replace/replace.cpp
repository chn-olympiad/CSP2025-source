#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> m;
string s1,s2;
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		m.insert(s1,s2);
	}
	return 0;
}
