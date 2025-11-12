#include <bits/stdc++.h>
using namespace std;
int a[12];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans="";
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			a[s[i]-'0']++;
	}
	int num=9;
	while(num>=0)
	{
		char k=num+'0';
		if(a[num])
		{
			ans+=k;
			a[num]--;
		}
		else	num--;
	}
	if(ans[0]=='0')
		cout<<0;
	else	cout<<ans;
	return 0;
}


