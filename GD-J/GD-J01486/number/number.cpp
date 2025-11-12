#include<bits/stdc++.h>
using namespace std;
int sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.length()]={0};
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+s.length());
	if(s.length()==sum)
	{
		for(int i=s.length()-1;i>=0;i--)
		{
			cout<<a[i];
		}
		return 0;
	}
	for(int i=s.length()-1;i>=s.length()-sum;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
