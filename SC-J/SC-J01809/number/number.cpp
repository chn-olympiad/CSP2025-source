#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	vector<long long> a;
	long long c;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			c=s[i]-'0';
			a.push_back(c);
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i];
	}
	return  0;
}