#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int s[1000006];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s1;
    cin>>s1;
    for(int i=0;i<s1.size();i++)
    {
    	if(s1[i]>='0'&&s1[i]<='9')
    	{
    		mp[s1[i]-'0']++;
		}
	}
	int e=0;
	for(auto k:mp)
	{
		if(k.second>=1)
		{
		    for(int i=0;i<k.second;i++)
		    {
		    	s[e]=k.first;
		    	e++;
			}
		}
	}
	for(int i=e-1;i>=0;i--)
	{
		cout<<s[i];
	}
	return 0;
}
