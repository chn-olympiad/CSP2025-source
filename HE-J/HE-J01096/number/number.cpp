#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[1000010];
int s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&s);
	int cnt=0;
	for(int i=1;i<=1000010;i++)
	{
	   if(s>0)
	   {
	   	  a[i]=s%10;
	   	  s/=10;
	   	  cnt++;
	   }
	   else break;
	}
    sort(a+1,a+1+cnt);
    for(int i=cnt;i>=1;i++) printf("%d",a[i]);
	return 0;
}
