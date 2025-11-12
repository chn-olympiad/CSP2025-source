#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
char s;
int a[1000010],j=0;
bool cmp(int i,int j)
{
	return i>j;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		if(s>='0'&&s<='9')
			j++,a[j]=s-'0';
	}
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++)
		printf("%d",a[i]);
	return 0;
}
