#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> a;
	for(long long int i=0;i<s.size();++i){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end());
	for(long long int i=a.size()-1;i>=0;--i){
		cout<<a[i];
	}
	return 0;
} 
