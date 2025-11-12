#include<cstdio>
using namespace std;

int n;
int a[30];
int max,sum;

int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);				Æ­£¡
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{	scanf("%d",&a[i]);	}
	
	if(n<3)
	{	printf("0");	}
	
	if(n==3)
	{
		max=0,sum=0;
		for(int i=1;i<=3;i++)
		{	if(a[i]>max) {	max=a[i];	}
			sum+=a[i];
		}
		if( sum>2*max ) {	printf("1");	}
		else {	printf("0");	}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

