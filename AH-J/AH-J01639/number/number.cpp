//number.cpp
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=1;
	char ch;
	while(scanf("%c",&ch)!=EOF)//~scanf("%c",&ch)
		if(ch>='0'&&ch<='9') a[j++]=ch-'0';
	sort(a+1,a+j,cmp);
	for(int i=1;i<j;i++)
		printf("%d",a[i]);
	return 0;
}
