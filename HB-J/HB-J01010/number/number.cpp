#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char a[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int book[15]={0};
    int flag=0;
    cin>>a;
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
		if(a[i]>='0'&&a[i]<='9')
		{
			book[a[i]-'0'+1]++;
		}
	}
	for(int i=10;i>=2;i--)
	{
		for(int j=1;j<=book[i];j++)
		{
			flag=1;
			cout<<i-1;
		}
	}
	if(flag==0)
	{
		cout<<0;
	}
	else if(flag==1)
	{
		for(int i=1;i<=book[1];i++)
		{
			cout<<0;
		}
	}
    return 0;
}
