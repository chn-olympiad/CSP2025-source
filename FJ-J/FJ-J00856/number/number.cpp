#include <bits/stdc++.h>
using namespace std;
string s;
int cmp(int x,int y)
{
	return x>y;
}
int a[1145141],len,cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
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
