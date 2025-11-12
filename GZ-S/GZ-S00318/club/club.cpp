//GZ-S00318 贵州省绥阳中学  王开润 
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct node{
	int a,b;
}q[200005];
node w[200005],e[200005];
bool comm(node c,node b)
{
	return c.a>=b.a;
}

int n;
int t=1,f=1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		bool sum[200005];
		memset(sum,0,sizeof(sum));
		int A=0,B=0,C=0;
		int AA=0,BB=0,CC=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>q[i].a>>w[i].a>>e[i].a;
			q[i].b=w[i].b=e[i].b=i;
			if(w[i].a==0)BB++;
			if(e[i].a==0)CC++;
		}
		
		if(BB==n&&CC==n)//性质A 
		{	sort(q+1,q+1+n,comm);
			for(int i=1;i<=n/2;i++)
			ans+=q[i].a;
			cout<<ans<<endl;
			continue;
		}//5.
		
		if(CC==n&&BB!=n)
		{
			sort(q+1,q+1+n,comm);
			sort(w+1,w+1+n,comm);
			for(int i=1;i<=n;i++)
			{
				if(B<=n/2&&A<=n/2)
				{
					if(q[i].a<=w[i].a&&q[i].b!=w[i].b&&!sum[w[i].b])
				{
					ans+=w[i].a;sum[w[i].a]=1;B++;
				}
				if(q[i].a>w[i].a&&q[i].b!=w[i].b&&!sum[q[i].b])
				{
					ans+=q[i].a;sum[q[i].b]=1;A++;
				}
				}
				else if(B>n/2&&A<=n/2)
				{
					if(!sum[q[i].b])
				{
					ans+=q[i].a;sum[q[i].b]=1;A++;
				}
				}else if(B<=n/2&&A>n/2)
				{
					if(!sum[w[i].b])
					ans+=w[i].a;sum[w[i].b]=1;B++;
				}
				else 
				{
					cout<<ans<<endl;
					continue;	
				}
			}
		}
			node p[200005];
			memset(p,0,sizeof(p));
			for(int i=1;i<=n;i++)
			{
				if(q[i].a>=w[i].a&&w[i].a>=e[i].a) p[i]=q[i];
				if(q[i].a<w[i].a&&w[i].a<e[i].a)p[i]=e[i];
				if(q[i].a<w[i].a&&w[i].a>e[i].a)p[i]=w[i];
			}
			for(int i=1;i<=n/2;n++)
			ans+=p[i].a;
			cout<<ans<<endl;
	}
	return 0;
 } 
 //	for(int i=1;i<=n;i++)
		//cout<<q[i].a<<" "<<q[i].b<<endl;
