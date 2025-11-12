#include<bits/stdc++.h>
using namespace std;
string s;
vector<long long> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),greater<long long>());
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
}
