#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string ans;
	char max;
	char t;
	cin>>s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			ans+=s[i];
		}
	}
	max = ans[0];
	sort(ans.begin(),ans.end());
	for(int i = ans.size() - 1;i>=0;i--)
	{
		cout<<ans[i];
	}	
	
	
	return 0;
}