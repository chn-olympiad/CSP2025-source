#include<bits/stdc++.h>
using namespace std;
int main()
{
 	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>v;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int x:v)
	{
		cout<<x;
	}
}
