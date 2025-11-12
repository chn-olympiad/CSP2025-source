#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int h[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			h[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=h[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
