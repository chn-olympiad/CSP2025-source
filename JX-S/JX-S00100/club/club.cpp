#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e5+10;
struct node{
	long long A;
	long long B;
	long long C;
}a[100010];
long long f[5000][5000];
long long n,T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&a[i].A,&a[i].B,&a[i].C);
		for(int i=1;i<=n;i++)
		{
			for(int x=n/2;x>=0;x--)
			{
				for(int y=n/2;y>=0;y--)
				{
					int z=i+n-x-y;
					int l1=INT_MIN,l2=INT_MIN,l3=INT_MIN;
					if(x>=1) l1=f[x-1][y]+a[i].A;
					if(y>=1) l2=f[x][y-1]+a[i].B;
					if(z>=1) l3=f[x][y]+a[i].C;
					f[x][y]=max({l1,l2,l3});
				}
			}
		}
		printf("%lld\n",f[n/2][n/2]);
		n=0;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
	}
	return 0;
}
//You will see the god unless you used long long
