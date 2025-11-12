#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int h = 0;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[h] = s[i]-'0';
			h++;
		}
	}
	sort(a,a+h,cmp);
	for(int i = 0;i<h;i++)
	{
		cout<<a[i];
	}
	return 0;
}
