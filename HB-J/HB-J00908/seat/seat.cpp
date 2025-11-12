#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int test[1000];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int x=n*m;
	for (int i=1;i<=x;i++)
		scanf("%d",&test[i]);
	int s=test[1];
	sort(test+1,test+1+x,cmp);
	int wz=0;
	for (int i=1;i<=x;i++)
	{
		if (s==test[i])
			wz=i;
	}
	int a=wz/n;
	if (wz%n!=0)
		a+=1;
	int b=wz%n;
	if (b==0)
		b=n;
	if (a%2==0)
		b=n-b+1;
	printf("%d %d\n",a,b);
	return 0;
}
