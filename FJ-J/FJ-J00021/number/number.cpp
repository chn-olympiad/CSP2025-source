#include <bits/stdc++.h>
using namespace std;
int number[10000000];
bool cmp(int x,int y)
{
	return x>y;
} 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int c=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			number[c]=a[i]-'0';
			c++;
		}
	}
	sort(number,number+c,cmp);
	bool flag=false;
	for(int i=0;i<c;i++)
	{
		if(number[i]!=0)
		{
			flag=true;
			break;
		}
	}
	if(flag)
	{
		for(int i=0;i<c;i++)
		{
			cout<<number[i];
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
	/*
	ÎØÎØÎØÎÒÒªAC 
	*/
}
