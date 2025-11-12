#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1,s2;
	cin>>s1;
	for (int i=0;i<s1.length();i++)
	{
		if (s1[i]>='0' && s1[i]<='9')
		{
			s2+=s1[i];
		}
	}
	long long a[1919810],num[1919810];
	int chang=s2.length();
	for (int i=0;i<chang;i++)
	{
		a[i+1]=s2[i]-'0';
	}
	sort(a+1,a+chang+1);
	for (int i=chang;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
