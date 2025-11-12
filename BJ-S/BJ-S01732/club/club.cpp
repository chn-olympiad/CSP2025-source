#include<bits/stdc++.h>
using namespace std;
int b[5];
long long c[5][100005];
int n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			long long x,y,z;
			cin>>x>>y>>z;
			c[4][1]=x;
			c[4][2]=y;
			c[4][3]=z;
			sort(c[4]+1,c[4]+4);
			long long q=c[4][3]-c[4][2];
			ans+=c[4][3];
			if(x==c[4][3])
			{
				b[1]++;
				c[1][b[1]]=q;
			}
			else
			{
				if(y==c[4][3])
				{
					b[2]++;
					c[2][b[2]]=q;
				}
				else if(z==c[4][3])
				{
					b[3]++;
					c[3][b[3]]=q;
				}
			}
		}
		int flag=0,d;
		for(int i=1;i<=3;i++)
		{
			if(b[i]>n/2)
			{
				d=i;
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			sort(c[d]+1,c[d]+b[d]+1);
			for(int i=b[d];i>n/2;i--)
			{
				ans-=c[d][b[d]-i+1];
			}
		}
		printf("%lld\n",ans);
		memset(b,0,sizeof(b));
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
