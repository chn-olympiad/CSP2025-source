#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[2000001]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int n=strlen(s);
	sort(s,s+n);
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			printf("%c",s[i]);
		}
	}
	return 0;
}
