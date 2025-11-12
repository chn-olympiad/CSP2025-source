#include <bits/stdc++.h>
using namespace std;
string s;
int a[1005],n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[++n]=s[i]-'0';
		}
	}
	for(int j=n;j>=1;j--)
	{
		for(int k=1;k<=j;k++)
		{
			if(a[k+1]>a[k])
			{
				swap(a[k],a[k+1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
