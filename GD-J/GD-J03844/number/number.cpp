#include<iostream>
#include<cstring>
using namespace std;
string a;
int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&a);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			num[int(a[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<num[i];j++)
		{
			printf("%d",i);
		}
		cout<<'0';
	}
	return 0;
}

