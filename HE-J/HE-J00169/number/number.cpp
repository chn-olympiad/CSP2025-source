#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main(){
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			v.push_back(int(s[i]-'0'));
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}
