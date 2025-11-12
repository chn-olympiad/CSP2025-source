#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool cmp(int x,int y)
{
	return x>y;
}
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			v.push_back(s[i]-'0');
		}
	}
	for(int i=0;i<v.size();i++)
	{
		a[i]=v[i];
	}
	sort(a+0,a+v.size(),cmp);
	for(int i=0;i<v.size();i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
