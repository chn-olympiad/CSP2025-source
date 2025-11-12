#include<iostream>
using namespace std;
int a[500005],w,n,k,m;
bool f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==k)
		{
			m++;
			f[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
		if(f[i]){w=0;continue;}
		else
		{
		    f[i]=1;
			w^=a[i];
			if(w==k){w=0;m++;}	
	    }
	printf("%d",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
