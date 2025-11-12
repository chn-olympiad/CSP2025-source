#include <bits/stdc++.h>
using namespace std;
vector<char> v;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;cin>>str;
	for(int i=0;i<str.size();i++) if(isdigit(str[i])) v.push_back(str[i]);
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++) cout<<v[i];
	return 0;
}