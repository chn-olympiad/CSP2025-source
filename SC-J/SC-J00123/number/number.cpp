#include<bits/stdc++.h>
using namespace std;
string str;
int a[1000005],n=0;
int main()
{
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='0'&&str[i]<='9') a[++n]=str[i]-'0';
	}
	sort(a+1,a+1+n);
	if(a[n]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}