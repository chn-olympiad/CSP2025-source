#include<bits/stdc++.h>
using namespace std;
string a;
char s[1000010];
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			cnt++;
			s[cnt]=a[i];
		}
	}
	sort(s+1,s+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<s[i];
	}
	return 0;
}