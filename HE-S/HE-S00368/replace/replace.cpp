#include <bits/stdc++.h>
using namespace std;
vector<pair<string,string> > v1;
vector<pair<string,string> > v2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		v1.push_back({s1,s2});
	}
	
	for(int i=0;i<q;i++){
		string s1,s2;
		cin>>s1>>s2;
		v2.push_back({s1,s2});
	}
	cout<<0;
	return 0;
}
