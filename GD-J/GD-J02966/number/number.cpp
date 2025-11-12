#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+100; 
string s;
int a[MAXN];
int cnt=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<int(s.length());i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-48;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for (int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
/*
6
*/ 
