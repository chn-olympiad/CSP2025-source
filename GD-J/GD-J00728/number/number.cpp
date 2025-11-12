#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	char cc;
	while(cin>>cc)
	{
		if(cc>='0'&&cc<='9')
		{
			a+=cc;
		}
	}
	
	
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='9')
			cout<<a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='8')
			cout<<a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='7')
			cout<<a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='6')
			cout<<a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='5')
			cout<<a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='4')
			cout<<a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='3')
			cout<<a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='2')
			cout<<a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='1')
			cout<<a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0')
			cout<<a[i];
	}
    return 0;
}



//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
//哈哈哈被我骗到了吧，


