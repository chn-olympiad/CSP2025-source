#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string s;

bool cmp(int a,int b)
{
	return a>b;
}

vector<int>v;
	
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	for(int i=0;i<(int)s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			v.push_back((int)s[i]-'0');
		}
	}
	
	sort(v.begin(),v.end(),cmp);
	
	for(int i=0;i<(int)v.size();i++)
	{
		cout<<v[i];
	}
}
