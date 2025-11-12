#include <bits/stdc++.h>
using namespace std;
string x;
int a[1001000],z;
bool cmp(int q,int p)
{
	return q>p;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]>='0'&&x[i]<='9')
		{
			a[++z]=x[i]-'0';
		}
	}
	sort(a+1,a+z+1,cmp);
	for(int i=1;i<=z;i++)
	{
		cout<<a[i];
	}
	return 0;
}
