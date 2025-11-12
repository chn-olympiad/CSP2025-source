#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,hs,hl,xz,hj[1000010][4],xl[11][1000010],z;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>hs>>hl>>xz;
	for(i=1;i<=hl;i++)
	{
		scanf("%lld%lld%lld",&hj[i][1],&hj[i][2],&hj[i][3]);
	}
	for(i=1;i<=hs;i++)
	{
		scanf("%lld",&hj[i][1]);
		for(j=1;j<=hl;j++)
		{
			scanf("%lld",&hj[j+1][1]);
		}
	}
	for(i=1;i<=hl;i++)
	{
		z=min(z,hj[i][3]);
	}
	printf("%lld",z*hs/2);
	return 0;
}
