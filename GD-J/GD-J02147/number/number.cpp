#include<bits/stdc++.h>
using namespace std;
vector<char> ch;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ch.push_back(s[i]);
		}
	}
	sort(ch.begin(),ch.end(),cmp);
	for(auto v:ch) cout<<v;
	return 0;
}
