#include <bits/stdc++.h>
using namespace std;
long long a[100005][3],b[5],c[5]={0,0,0,0,0},s1,s2,s3;
int main(){
	freopen("club.in","r",stdin);
	froepen("club.out","w",stdout);
	long long t,n;
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		c[i]=0;
		scanf("%lld",&n);
		for(int j=1;j<=n;j++)
		{
			for(int z=1;z<=3;z++)
			{
				scanf("%lld",&a[j][z]);
				if(a[j][z]>a[j][z+1]&&a[j][z]>a[j][z+2])
				{
					c[i]+=a[j][z];
					s1++;
				}
				if(a[j][z+1]>a[j][z]&&a[j][z+1]>a[j][z+2])
				{
					c[i]+=a[j][z+1];
					s2++;
				}
				if(a[j][z+2]>a[j][z+1]&&a[j][z+2]>a[j][z])
				{
					c[i]+=a[j][z+2];
					s3++;
				}
			}
		}
		printf("%lld\n",c[i]);
	}
	return 0;
}
