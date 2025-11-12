#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s;
vector<char> v;
auto cmp=[](char x,char y){return x>y;};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i:v)
	{
		cout<<i;
	}
} 
