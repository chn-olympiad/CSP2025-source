#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int num=0;
	int h=s.size();
	for(int i=0;i<h;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			num++;
			a[num]=s[i]-48;
		}
	}
	sort(a+1,a+num+1);
	if(a[num]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=num;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
