#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[1005];
int box[11];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s);
	for(int i = 0;i < strlen(s);i++)
	{
		char c = s[i];
		if('0' <= c && c <= '9')
		{
			int x = c - '0';
			box[x] ++;
		}
	}
	for(int i = 9; i >= 0;i--)
	{
		for(int j = 1;j <= box[i];j++)
		{
			printf("%d",i);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
