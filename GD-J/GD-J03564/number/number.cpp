#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
char a[1000005],num[1000005],r;
bool cmp(char a,char b){return a>b;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='0'&&a[i]<='9') num[++r]=a[i];
	}
	sort(num+1,num+r+1,cmp);
	for(int i=1;i<=r;i++) printf("%c",num[i]);
	printf("\0");
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
