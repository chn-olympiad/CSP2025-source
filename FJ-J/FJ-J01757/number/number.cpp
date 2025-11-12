#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<char> str;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i] <= '9')
		{
			str.push_back(s[i]);
		}
	}
	for(int i=0;i<str.size();i++)
	{
		char mx='0';
		int ii=0;
		for(int j=0;j<str.size();j++)
		{
			if(str[j]>='0' && str[j] <= '9'&& str[j] > mx)
			{
				mx=str[j];
				ii=j;
			}
		}
		cout<<mx;
		str[ii]='A';
	}
	return 0;
}
