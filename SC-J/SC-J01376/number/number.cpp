#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int t=s[i]-48;
			a[x]=t;
			x++;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0; 
}