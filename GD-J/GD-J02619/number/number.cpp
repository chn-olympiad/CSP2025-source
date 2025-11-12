#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(const char& a,const char& b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string ans;
	for(auto c : s)
	{
		if(c >= '0' && c <= '9')
		ans+=c;
	}sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
}
