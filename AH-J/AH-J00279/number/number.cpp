#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	string s,ans;
	cin>>s;
	t=s.size();
	for(int i=0;i<t;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			ans+=s[i];
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
	return 0;
}
