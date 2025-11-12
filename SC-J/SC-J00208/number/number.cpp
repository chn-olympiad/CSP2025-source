#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int c=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[c]=s[i]-48;
			c++;
		}
	}
	sort(a,a+c,cmp);
	for(int i=0;i<c;i++)
	{
		cout<<a[i];
	}
	return 0;
}