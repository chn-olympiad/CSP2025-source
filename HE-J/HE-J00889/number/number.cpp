#include <bits/stdc++.h>
using namespace std;
string s;
int a[100005],p;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(int(s[i])>47&&int(s[i])<58)
		{
			p++;
			a[p]=int(s[i]-48);
		}
	}
	sort(a+1,a+1+p);
	for(int i=p;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
