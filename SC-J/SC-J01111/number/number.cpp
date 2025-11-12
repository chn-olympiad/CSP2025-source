#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int sz=0;
	string s;
	cin>>s;
	vector<int> v;
	for(int i=0;i<s.length();i++){
		if(!(islower(s[i]))){
			v.push_back(s[i]-'0');
			sz++;
		}
	}
	sort(v.begin(),v.end());
	for(int i=sz-1;i>=0;i--){
		cout<<v[i];
	}
    return 0;
}