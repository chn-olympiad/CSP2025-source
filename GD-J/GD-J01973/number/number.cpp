#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
char s[N];
int n;
int cnt=0;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]==0)
	printf("0");
	else
	{
		for(int i=cnt;i>=1;i--)
		printf("%d",a[i]);
	}
	return 0; 
}
