#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s;
int a[10];
int tmp;
int nu(char x)
{
	if(x=='0')
		return 0;
	if(x=='1')
		return 1;
	if(x=='2')
		return 2;
	if(x=='3')
		return 3;
	if(x=='4')
		return 4;
	if(x=='5')
		return 5;
	if(x=='6')
		return 6;
	if(x=='7')
		return 7;
	if(x=='8')
		return 8;
	return 9;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&s)==1)
	{
		if(s>='0'&&s<='9')
			a[nu(s)]++;
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		for(int j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
 } 
