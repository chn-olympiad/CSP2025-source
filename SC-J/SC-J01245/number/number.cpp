#include<iostream>
#include<cstdio>
using namespace std;
int num[10]={};
char a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b=0;
	while(cin>>a)
	{
		if(a=='9')
		{
			num[9]++;
		}
		else if(a=='8')
		{
			num[8]++;
		}
		else if(a=='7')
		{
			num[7]++;
		}
		else if(a=='6')
		{
			num[6]++;
		}
		else if(a=='5')
		{
			num[5]++;
		}
		else if(a=='4')
		{
			num[4]++;
		}
		else if(a=='3')
		{
			num[3]++;
		}
		else if(a=='2')
		{
			num[2]++;
		}
		else if(a=='1')
		{
			num[1]++;
		}
		else if(a=='0')
		{
			num[0]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<num[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}