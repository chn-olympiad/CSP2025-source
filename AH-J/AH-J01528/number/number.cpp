#include<bits/stdc++.h>
using namespace std;
bool cmp(int q, int p)
{
	return q>p;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	short a[1111111];
	int l=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[l++]=int(s[i]-'0');
	}
	sort(a,a+l,cmp);
	for(int i=0;i<l;i++)
	{
		cout<<a[i];
	}
	return 0;
}

