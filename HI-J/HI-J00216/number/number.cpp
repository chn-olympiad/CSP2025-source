#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int> v;
	cin>>s;
	for(char a:s){
		if(a>='0'&&a<='9'){
			int b=a-'0';
			v.push_back(b);
		}
	}
	sort(v.begin(),v.end());
	if(v[v.size()-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}
