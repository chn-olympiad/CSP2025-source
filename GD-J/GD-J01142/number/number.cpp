#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int n,a[maxn];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			printf("%d",i);
	return 0;
}
