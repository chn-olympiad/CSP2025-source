#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v;
string s;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0') v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end(),[](int x,int y){return x>y;});
	if(v[0]==0) return cout<<0,0;
	for(auto num:v) cout<<num;
	return 0;
} 
