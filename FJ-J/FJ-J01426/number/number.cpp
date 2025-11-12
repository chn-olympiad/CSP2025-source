#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int ls=s.size();
	for(int i=0;i<ls;i++){
		if('0'<=s[i]&&'9'>=s[i])v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end(),greater<int>());
	int lv=v.size();
	for(int i=0;i<lv;i++){
		cout<<v[i];
	}
	return 0;
}

