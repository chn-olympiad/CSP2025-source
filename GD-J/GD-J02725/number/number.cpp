#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	vector<int> v;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			v.push_back(int(s[i]-'0'));
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--)cout<<v[i];
	return 0;
}
