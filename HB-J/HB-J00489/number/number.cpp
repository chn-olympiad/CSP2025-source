#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
int a[1000005],n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]>='0'&&x[i]<='9')
		{
			n++;
			a[n]=x[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<a[i];
    return 0;
}
