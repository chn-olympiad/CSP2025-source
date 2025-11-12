#include <bits/stdc++.h>
using namespace std;
const int cd1 = 2e5+5;
const int cd2 = 5e6+5;
string str1[cd1][3];
string str2[cd1][3];
map<string,bool>;
int dp[cd2][cd2];
int n,q;
int main()
{
	cin>>n>>q;
	for(int i = 1;i<=n;i++)
	{
		cin>>str1[i][1]>>str1[i][2];
		map[str1[i][1]] = 1;
		map[str1[i][2]] = 1;
	}
	for(int i = 1;i<=q;i++)
	{
		cin>>str2[i][1]>>str2[i][2];
		for(int j = 1;j<=str2[i][1].size();j++)
		{
			for(int k = 1;k<=str2[i][2].size();k++)
			{
				for(int d = j;d>=1;d--)
				{
					string s;
					for(int u = 1;u<=d;u++)
					{
						s.insert(0,st)
					}
				}
			}
		}
		cout<<dp[str2[i][1].size()][str2[i][1].size()]<<endl;
	}
	return 0;
}
