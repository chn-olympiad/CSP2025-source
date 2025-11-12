#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>=b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> num;
	for(long unsigned int i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))
		{
			int tmp=s[i]-'0';
			num.push_back(tmp);
		}
	}
	sort(num.begin(),num.end(),cmp);
	if(num[0]==0)
	{
		cout<<0;
		return 0;
	}
	for(long unsigned int i=0;i<num.size();i++)
	{
		cout<<num[i];
	}
	return 0;
}
