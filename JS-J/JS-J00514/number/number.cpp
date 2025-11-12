#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[1000010],l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=int(s.size());
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
