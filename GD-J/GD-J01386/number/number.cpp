#include <bits/stdc++.h>
using namespace std;

vector<int> num(10,0);
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	getline(cin,s);
	for(int i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))
		{
			num[s[i]-'0']++;
		}
	}
	if(num[9]==0 && num[8]==0 && num[7]==0 && num[6]==0 && num[5]==0 && num[4]==0 && num[3]==0 && num[2]==0 && num[1]==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=9;i>=0;i--)
		{
			for(int j=1;j<=num[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
