
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
int a[1000010],cnt;
char s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		if(s>='0' && s<='9')
		{
			a[++cnt]=s-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<a[i];
	return 0;	
}
