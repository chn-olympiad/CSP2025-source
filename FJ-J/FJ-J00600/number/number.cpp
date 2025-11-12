#include<bits/stdc++.h>
using namespace std;
string s;
int t=0,sz=0,a[1000005];
char c;
int main()
{
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=1000005;i++)
	{
		if(s[t]=='\0')
		{
			break;
		}
		if(s[t]<='9'&&s[t]>='0')
		{
			sz++;
			a[t]=s[t];
		}
		t++;
	}
	sort(a,a+t);
	for(int i=t;i>t-sz;i--)
	{
		c=a[i-1];
		cout<<c;
	}
	return 0;
}
