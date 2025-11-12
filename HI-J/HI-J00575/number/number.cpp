#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<functional>
using namespace std;
string res;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))
		{
			res+=s[i];
		}
	}
	sort(res.begin(),res.end(),greater<int>());
	cout<<res;
	return 0;
}
