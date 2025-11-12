#include <cstdio>
#include <algorithm>
using namespace std;
int a[100];
bool cmp(int x,int y)
{
	if(x == y) return true;
	return x > y;	
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,r;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++)
	{
		scanf("%d",&a[i]);
	}
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == r)
		{
			r = i;
			break;
		}
	}
	int s = r % n;
	int k = r / n;
	if(s == 0)
	{
		if(k & 1)
		{
			printf("%d %d",k,n);
		}
		else if((k & 1) == 0)
		{
			printf("%d %d",k,1);
		}
	}
	else
	{
		int k2 = k + 1;
		if(k2 & 1)
		{
			printf("%d %d",k2,s);
		}
		else if((k2 & 1) == 0)
		{
			printf("%d %d",k2,n - s + 1);
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
