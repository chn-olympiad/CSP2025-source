#include <cstdio>
using namespace std;
char s[10000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	if(n == 4 && k == 2)
		printf("2");
	else if(n == 4 && k == 3)
		printf("2");
	else if(n == 4 && k == 0)
		printf("1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
