#include <bits/stdc++.h>
using namespace std;

int num[1000001];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int pos=1,len;
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			num[pos]=s[i]-'0';
			pos++;
		}
	}
	sort(num+1,num+pos,cmp);
	for(int i=1;i<pos;i++)
	{
		cout<<num[i];
	}
	return 0;
}