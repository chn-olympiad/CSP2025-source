#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cnt(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int t=0;
	cin>>s;
	for (int i=0;i<s.size();++i)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1,cnt);
	for (int i=1;i<=t;++i)
	{
		cout<<a[i];
	}
	return 0;
}
