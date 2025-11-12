#include<bits/stdc++.h>
using namespace std;
int t;
int read()
{
	int num=0,k=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=num*10+c-'0';
		c=getchar();
	}
	return num*k;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int num[4],n,a[110000][4];
		long long ans=0;
		priority_queue<int, vector<int> ,greater<int> > q[4];
		num[1]=num[2]=num[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int maxx=0,x;
			for(int j=1;j<=3;j++)
		  	{
		  		a[i][j]=read();
		  		if(a[i][j]>maxx)
		  		{
		  			maxx=a[i][j];
		  			x=j;
				}
		  	}
		  	ans+=maxx;
		  	num[x]++;
		  	int minn=INT_MAX;
		  	for(int j=1;j<=3;j++)
		  	  if(j!=x)
		  	    minn=min(minn,maxx-a[i][j]);
		  	q[x].push(minn);
		  	
		}  
		for(int j=1;j<=3;j++)
		  if(num[j]>n/2)
		  {
		  	int tot=num[j]-n/2;
		  	while(tot--)
		  	{
		  		int k=q[j].top();q[j].pop();
		  		ans-=k;
			}
		  }
		printf("%lld\n",ans);
	}
	return 0;
}