#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<long long>v;
	
	int k=0;
	for(long long i=0;i<s.length();i++){
		if(s[i]-'0'<=9){
			v.push_back(s[i]-'0');
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=0;j<v.size();j++){
			if(v[j]==i){
				cout<<v[j];
			}
		}
	}
	return 0;
}
