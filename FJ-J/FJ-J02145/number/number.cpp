#include<bits/stdc++.h>
using namespace std;
int len,cnt=0;
int a[1000010];
string s;
bool cmp(int o,int p)
{
	return o>p;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
