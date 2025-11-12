#include<bits/stdc++.h>
using namespace std;
int j=0,a[1000005];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			j++;
			a[i]=s[i]-48;
		}	
	}
	sort(a,a+s.size(),greater<int>());
	if(a[0]==0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<j;i++)
	cout<<a[i];
	cout<<endl;
	return 0;
 }

