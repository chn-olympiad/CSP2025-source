#include <bits/stdc++.h>
using namespace std;
#define N 1000010
char ch;
int a[N],now=0;
bool cmp(int d ,int f)
{
	return d>f;
}
int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	ch=getchar();
	while(('0'<=ch&&ch<='9')||('a'<=ch&&ch<='z'))
	{
		if('0'<=ch&&ch<='9')a[++now]=ch-'0';
		ch=getchar();
	}
	sort(a+1,a+now+1,cmp);
	for(int i=1;i<=now;i++)
	{
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
