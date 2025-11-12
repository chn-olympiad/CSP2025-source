#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e6+5;
int n,a[N];
char s[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int tmp=s[i]-48;
			a[tmp]++;
		}
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			printf("%d",i);
	return 0;
}
