#include<bits/stdc++.h>
using namespace std;
string s;
int a[2000005],cn=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cn++;
			a[cn]=s[i]-'0';
		}
	}
	sort(a+1,a+cn+1);
	for(int i=cn;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
