#include<cstdio>
using namespace std;

int n,k;
int a[110];
int cnt;

int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);				Æ­£¡
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
	{	scanf("%d",&a[i]);	}
	
	if(k==1)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{	if(a[i]==1)
			{	cnt+=1;	 }
		}
		printf("%d",cnt);
	}
	
	if(k==0)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{	if(a[i]==0)
			{	cnt+=1;	 }
			if( a[i-1]==1 && a[i]==1 )
			{	cnt+=1;i++;	}
		}
		printf("%d",cnt);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

