#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	vector<int> a;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end());
	for(long long i=a.size()-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
