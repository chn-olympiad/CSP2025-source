#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	if (n<3)
	{
		printf("0\n");
		return 0;
	}
	int sum=0,max=0;
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if (x>=max)
			max=x;
		sum+=x;
	}
	if (sum>(2*max))
		printf("1\n");
	else
		printf("0\n");
	return 0;
}
