#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>a;
	for(char c:s){
		if(c>='0'&&c<='9')a.push_back(c-48);
	}
	sort(a.begin(),a.end());
	while(!a.empty()){
		cout<<a.back();
		a.pop_back();
	}
	return 0;
	}
