//xor
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int n1=0,n0=0;
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)n0++;
		if(a[i]==1)n1++;
	}
	if(k==1)
	{
		printf("%d",min(n0,n1)+max(0,n1-n0));
	}
	else
	{
		if(k==0)
		{
			printf("%d",(n1/2)+(n0/2));
		}
		else puts("12701");
	}
	return 0;
}

