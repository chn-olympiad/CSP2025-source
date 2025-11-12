#include<bits/stdc++.h>

using namespace std;
int a[1000010];
bool cmp(int a,int b)
{
	if(a>b)
		return true;
	else
		return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++)
	{
		cout<<a[i];
	}
	return 0;
}
