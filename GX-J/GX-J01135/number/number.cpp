#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int count = 0;
	string ans="";
	cin>>s;
	int l = s.size()-1;
	for(int i = 0;i <= l;i++)
	{
		if(s[i]>='0' && s[i] <= '9')
		{
			count++;
			a[count]=s[i];
		}
	}
	sort(a+1,a+count+1);
	for(int i=count;i>=1;i--)
	{
		if(ans=="")
		{
			if(a[i]>'0')
			{
				ans=ans+a[i];
			}
		}else
		{
			ans=ans+a[i];
		}
	}
	cout<<ans;
	return 0;
}
