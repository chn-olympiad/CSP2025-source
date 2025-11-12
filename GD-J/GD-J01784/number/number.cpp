#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string s;
vector<int> ans;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	int len = s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9') ans.push_back(s[i]-'0');
	}
	
	sort(ans.begin(),ans.end());
	
	for(int i=ans.size()-1;i>=0;i--)
	{
		cout<<ans[i];
	}
	return 0;
}
