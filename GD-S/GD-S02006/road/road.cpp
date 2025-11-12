#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
long long n,m,num,sum,k,a[N],b[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if(a[x]==0||a[y]==0)
		{
			num+=z;
			a[x]++;
			a[y]++;
		}
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>b[i];
		}
	}
	printf("%lld",num);
	return 0;
}
