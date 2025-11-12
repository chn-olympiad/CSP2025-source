#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
vector<char> ve;
bool cmp(char a,char b)
{
	return (a>b);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s)
	{
		if(c>='0'&&c<='9')
		{
			ve.push_back(c);
		}
	}
	stable_sort(ve.begin(),ve.end(),cmp);
	for(char c:ve)
	{
		cout<<c;
	}
	return 0;
}