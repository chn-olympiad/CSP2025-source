#include <bits/stdc++.h>
using namespace std;
int main()
{
   freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
	string s;
	int ans=0;
	char big='0';
	vector<char> a(1000000);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[ans]=s[i];
			ans++;
		 } 
	}
	for(int i=0;i<ans;i++)
	{
		for(int j=ans-1;j>i;j--)
		{
			if(a[j]>a[i])
			{
				big=a[i];
				a[i]=a[j];
				a[j]=big;
			}
		}
		
	}
	for(int i=0;i<ans;i++)
	{
		cout<<a[i];
	}
	return 0;
 } 
