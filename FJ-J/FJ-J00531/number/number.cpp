#include <bits/stdc++.h>
using namespace std;
int a[1000010],idx;
int main()
{
	string s;
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);//yao gai
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[idx]=s[i]-'0';
			//cout<<a[idx];
			idx++;
		}
	}
	sort(a,a+idx);
	for(int i=idx-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
