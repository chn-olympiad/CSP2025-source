#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,a,b;
	string s1,s2;
	map<pair<string,string>,vector<pair<string,string>>> s;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		for(a=0;s1[a]==s2[a];a++);
		for(b=s1.size();s1[b]==s2[b];b++);
		s[{string(s1.begin()+a,s1.end()-b),string(s2.begin()+a,s2.end()-b)}]
			.push_back({string(s1.begin(),s1.begin()+a),string(s1.end()-b,s1.end())});
	}
	for(int j=0;j<q;j++){
		cin>>s1>>s2;
		for(a=0;s1[a]==s2[a];a++);
		for(b=s1.size();s1[b]==s2[b];b++);
		for(auto pr:s[{string(s1.begin()+a,s1.end()-b),string(s2.begin()+a,s2.end()-b)}])cout<<pr.first<<pr.second;
	}
	cout<<204;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
