#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int num,cnt=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9' && s[i]>='0')
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+0,a+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
