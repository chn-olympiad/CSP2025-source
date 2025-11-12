#include<bits/stdc++.h>
using namespace std;
const long long N = 1e4+1001;
struct node
{
	long long x[4]={0,0,0,0};
	long long flag=0;
};
bool cmp(node x1,node x2)
{
	return x1.x[1]>x2.x[1];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	for(long long cnt=1;cnt<=t;cnt++)
	{
		node a[N];
		long long b[4][N];
		long long c[4];
		long long n,m;
		cin>>n;
		memset(c,0,sizeof(c));
		long long flag1=0,flag2=0;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].x[1],&a[i].x[2],&a[i].x[3]);
			if(a[i].x[2]) flag1=1;
			if(a[i].x[3]) flag2=1;
		}
		if(n==1)//subtask n<=2;
		{
			cout<<max(a[1].x[1],max(a[1].x[2],a[1].x[3]));
		}
		else if(n==2)//Subtask n<=2;
		{
			long long ans=0;
			for(long long i=1;i<=3;i++)
			{
				for(long long j=1;j<=3;j++)
				{
					if(i==j) continue;
					ans=max(ans,a[1].x[i]+a[2].x[j]);
				}
			}
			cout<<ans<<endl;
		}
		else if(!flag1&&!flag2)//Subtask A
		{
			long long ans=0;
			sort(a+1,a+1+n,cmp);
			for(long long i=1;i<=n/2;i++)
			{
				ans+=a[i].x[1]; 
			}
			cout<<ans<<endl;
		}
		else if(n==4)
		{
			long long ans=0;
			for(long long i=1;i<=3;i++)
			{
				for(long long j=1;j<=3;j++)
				{
					for(long long k=1;k<=3;k++)
					{
						for(long long y=1;y<=3;y++) 
						{
							if((i==j&&j==k)||(i==j&&j==y)||(i==k&&k==y)||(j==k&&k==y)) continue;
							ans=max(ans,a[1].x[i]+a[2].x[j]+a[3].x[k]+a[4].x[y]);
							//cout<<i<<" "<<j<<" "<<k<<" "<<y<<" "<<a[1].x[i]+a[2].x[j]+a[3].x[k]+a[4].x[y]<<endl;
						}
					}
				}
			}
			cout<<ans<<endl;
		}	
	}
	return 0;
}
