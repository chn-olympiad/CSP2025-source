#include<bits/stdc++.h>
using namespace std;
map<string,string> s;
string b1,b2,t1,t2;
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	s[""]="";
	for(int i=0;i<n;i++) cin>>b1>>b2,s[b1]=b2;
	for(int i=0;i<m;i++){
		cin>>t1>>t2;
		if(s[t1]!="") cout<<"1\n";
		else cout<<"0\n";
	}
	return 0;
}
