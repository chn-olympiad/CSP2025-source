#include<bits/stdc++.h>
using namespace std;
int n=0,a[1145140],p=0,cnt=0;
string s;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			p++;
			a[p]=s[i]-'0';
		}
	}
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=p;i++)
	{
		cnt=cnt*10+a[i];
	}
	cout<<cnt;
	return 0;
}
