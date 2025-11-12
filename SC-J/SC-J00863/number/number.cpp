#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	if(v[0]==0){
		cout<<0,exit(0);
	}
	for(auto i:v){
		cout<<i;
	}
	return 0;
}