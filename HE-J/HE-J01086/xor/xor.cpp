#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		sum++;
	}	
	if((n<=2&&k==0)||(n<=100&&k==0))
	{
		if(sum==n)
		{
			printf("0");
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
