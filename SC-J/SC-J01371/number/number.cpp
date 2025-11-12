#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
string s;
int len;
vector<int>a;
bool comp(int l,int r)
{
	return l>r;
}
int main()
{
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	int i;
	cin>>s;
	len=s.length();
	a.clear();
	for(i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int val=s[i]-'0';
			a.push_back(val);
		}
	}
	sort(a.begin(),a.end(),comp);
	for(auto u:a)
	{
		cout<<u;
	}
	return 0;
}