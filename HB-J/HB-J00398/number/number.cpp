#include <bits/stdc++.h>
using namespace std;
int a[1000005],cnt;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a,a+cnt,greater<int>());
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
