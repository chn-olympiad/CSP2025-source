#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1e6+10;
char s[N];
int t[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9') t[++m]=s[i]-'0';
	sort(t+1,t+m+1,cmp);
	if(!t[1]) printf("0");
	else
	{
		for(int i=1;i<=m;i++)
			printf("%d",t[i]);
	}
	return 0;
}
