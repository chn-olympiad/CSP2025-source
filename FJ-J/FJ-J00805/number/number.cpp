#include<bits/stdc++.h>
using namespace std;
int s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int x=1;
	for (int i=0;i<a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			s[x]=a[i]-'0';
			x++;
		}
	}
	sort(s+1,s+x);
	for(int i=x-1;i>=1;i--)
	{
		cout<<s[i];
	}
	return 0;
}
