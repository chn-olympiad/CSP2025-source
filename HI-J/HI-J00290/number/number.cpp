#include <bits/stdc++.h>
using namespace std;
string s;
vector<char>v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (isdigit(s[i])) v.push_back(s[i]);
	}
	sort(v.begin(),v.end(),greater<int>());
	for (int i=0;i<v.size();i++) cout<<v[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
