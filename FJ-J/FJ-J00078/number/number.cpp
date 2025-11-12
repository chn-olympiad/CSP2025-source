#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char in[N];
int ot[N],cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	scanf("%s",in+1);
	n=strlen(in+1);
	for (int i=1;i<=n;i++)
	{
		if ('0'<=in[i]&&in[i]<='9')
		{
			ot[++cnt]=(in[i]-'0');
		}
	}
	sort(ot+1,ot+cnt+1);
	for (int i=cnt;i>=1;i--)
	{
		printf("%d",ot[i]);
	}
	return 0;
}
