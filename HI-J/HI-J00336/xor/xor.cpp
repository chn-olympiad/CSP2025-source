#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    int z=0;
    int y=0;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	if(a[i]==0)
    	{
    		z++;
		}
		if(a[i]==1)
		{
			y++;
		} 
	}
	int ret=0;
	if(k==0)
	{
		ret=z+y/2;
	}
	if(k==1)
	{
		ret=y;
	}
	printf("%d",ret);
	return 0;
}

