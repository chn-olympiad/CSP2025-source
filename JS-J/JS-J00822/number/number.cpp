#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<char> v;
	for(auto i:s){
		if(i>='0' and i<='9'){
			v.push_back(i);
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
			cout<<v[i];
	}
	return 0;
}
