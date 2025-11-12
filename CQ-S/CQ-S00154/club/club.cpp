#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,j,ans;
long long t,sum,cmp,cmt,cmd,c[200005],h,e;
struct node{
	long long x,y,z;
}a[200005];
struct nod{
	long long u,v,w;
}b[600005];
bool cmmp(nod A,nod B)
{
	return A.u>B.u;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		ans=0;sum=0;cmp=0;cmt=0;cmd=0;h=0;e=0;
		cin>>n;
		m=n/2;
		for(long long j=1;j<=n;j++)
		{
			cin>>a[j].x>>a[j].y>>a[j].z;
			b[++sum].u=a[j].x;
			b[sum].v=j;
			b[sum].w=1;
			b[++sum].u=a[j].y;
			b[sum].v=j;
			b[sum].w=2;
			b[++sum].u=a[j].z;
			b[sum].v=j;
			b[sum].w=3;
		}
		sort(b+1,b+1+n*3,cmmp);
//		for(long long j=1;j<=n*3;j++)
//		{
//			cout<<b[j].u<<" "<<b[j].v<<" "<<b[j].w<<endl;
//		}
		for(long long j=1;j<=n*3;j++)
		{
			e=0;
			for(long long k=1;k<=h;k++)
			{
				if(b[j].v==c[k])
				{
					e=1;
					break;
				}
			}
			if(e==1)
			{
				continue;
			}
			c[++h]=b[j].v;
			if(b[j].w==1)
			{
				if(cmp>=m)
				{
					continue;
				}
				cmp++;
				ans+=b[j].u;
			}
			if(b[j].w==2)
			{
				if(cmt>=m)
				{
					continue;
				}
				cmt++;
				ans+=b[j].u;
			}
			if(b[j].w==3)
			{
				if(cmd>=m)
				{
					continue;
				}
				cmd++;
				ans+=b[j].u;
			}	
//			cout<<ans<<" ";
		}
		cout<<ans<<endl;
	}
	return 0;
}
