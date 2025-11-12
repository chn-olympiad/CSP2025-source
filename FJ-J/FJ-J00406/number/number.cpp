#include<bits/stdc++.h>
using namespace std;
string s="";
vector<char> a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a.push_back(s[i]);
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	for(char c:a)
	{
		cout<<c;
	}
	return 0;
 } 
