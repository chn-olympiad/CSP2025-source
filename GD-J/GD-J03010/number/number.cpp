#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[s[i]-'0'].push_back(s[i]-'0');
	for(int i=9;i>=0;i--)
		for(int j=0;j<a[i].size();j++)
			cout<<a[i][j];
	return 0;
}
