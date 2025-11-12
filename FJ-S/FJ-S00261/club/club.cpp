#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005][5],ma;
int b[5],c[100005];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		ma=0;
		memset(a,0,sizeof(a));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])b[1]++,c[i]=1;
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])b[2]++,c[i]=2;
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])b[3]++,c[i]=3;
		}
		while(b[1]>n/2||b[2]>n/2||b[3]>n/2)
		{
			
		}
	}
	return 0;
}
