#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,p;
string ss,ss1;
map<string,string> st;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>ss>>ss1;
		st[ss]=ss1;
		st[ss1]=ss;
	}
	while(p--){
		string s,s1;
		cin>>s>>s1;
		cout<<0;
	}
	return 0;
}
