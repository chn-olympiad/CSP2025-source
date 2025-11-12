#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string s;
int n=0;
int main()
{
	vector<int> v;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			v.push_back(s[i]-'0');
			n++;
		}
	}
	sort(v.begin(),v.end());
	for(int i=n-1;i>=0;i--)
	{
		cout<<v[i];
	}
	return 0;
}
