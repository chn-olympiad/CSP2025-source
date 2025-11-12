#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int n,s[15] = {0};
	cin>>a;
	n = a.size();
	for(int i =0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			s[a[i]-'0']++;
		}
	}
	for(int i = 9;i>=0;i--)
	{
		for(int k = 1;k<=s[i];k++)
		{
			cout<<i;
		}
	}
	return 0;
}
