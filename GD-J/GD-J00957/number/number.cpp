#include<bits/stdc++.h>
using namespace std;
int a[100001]={},ans=0;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans++;
			a[ans]=s[i]-'0';
		}
	}
	sort(a+1,a+ans+1);
	for(int i=ans;i>0;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
