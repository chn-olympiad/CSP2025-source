#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int j='9';j>='0';j--)
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==j)
			{
				cout<<s[i];
			}
		}
	}
	return 0;
}