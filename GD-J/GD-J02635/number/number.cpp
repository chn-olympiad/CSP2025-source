#include<bits/stdc++.h>
using namespace std;

string s;
multiset<char,greater<char>> ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			ans.insert(s[i]);
		}
	}
	for(auto i:ans)
	{
		cout<<i;
	}
	return 0;
} 
