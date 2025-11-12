#include<bits/stdc++.h>

using namespace std;

long long t,n,a1[100001],a2[100001],a3[100001],p=0,q=0;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>n;
		for(long long j=1;j<=n;j++)
		{
			
			cin>>a1[j]>>a2[j]>>a3[j];
			if(a2[j]==0)
			{
				p++;
			}
			if(a3[j]==0)
			{
				q++;
			}
		}
		if(n==2)
		{
			long long ans[9],ans1=0;
			ans[0]=a1[1]+a2[2];
			ans[1]=a1[1]+a3[2];
			ans[2]=a2[1]+a1[2];
			ans[3]=a2[1]+a3[2];
			ans[4]=a3[1]+a1[2];
			ans[5]=a3[1]+a2[2];
			for(long long x=0;x<6;x++)
			{
				ans1=max(ans1,ans[x]);
			}
			cout<<ans1<<endl;
			return 0;
		}
		if(q==n and p==n)
		{
			long long ans1=0;
			sort(a1+1,a1+1+n);
			for(long long x=0;x<n/2;x++)
			{
				ans1+=a1[n-x];
			}
			cout<<ans1<<endl;
		}
		if(q==n)
		{   bool w1[100001]={};
			long long ans1=0,ans2=0,max1[100001]={},max2[100001];
			for(long long x=1;x<=n;x++)
			{
				max1[x]=max(max1[x-1],a1[x]);
				if(max1[x]!=a1[x])
				{
					max1[x]==0;
				}
			}
			sort(max1+1,max1+1+n);
			for(long long x=1;x<=n/2;x++)
			{
				ans1+=max1[n-x+1];
				for(long long y=1;y<=n;y++)
				{
					if(a1[y]==max1[n-x+1])
					{
						w1[y]=1;
					}
				}
			}
			for(long long x=1;x<=n;x++)
			{
				if(w1[x]!=1)
				{
					max2[x]=max(max2[x-1],a2[x]);
				}
				if(max2[x]!=a2[x])
				{
					max2[x]=0;
				}
			}
			sort(max2+1,max2+1+n);
			for(long long x=1;x<=n/2;x++)
			{
				ans1+=max2[n-x+1];
			}
			bool w2[100001]={};
			for(long long x=1;x<=n;x++)
			{
				max2[x]=max(max2[x-1],a2[x]);
				if(max2[x]!=a2[x])
				{
					max2[x]==0;
				}
			}
			sort(max2+1,max2+1+n);
			for(long long x=1;x<=n/2;x++)
			{
				ans2+=max2[n-x+1];
				for(long long y=1;y<=n;y++)
				{
					if(a2[y]==max2[n-x+1])
					{
						w2[y]=1;
					}
				}
			}
			for(long long x=1;x<=n;x++)
			{
				if(w2[x]!=1)
				{
					max1[x]=max(max1[x-1],a1[x]);
				}
				if(max1[x]!=a1[x])
				{
					max1[x]=0;
				}
			}
			sort(max1+1,max1+1+n);
			for(long long x=1;x<=n/2;x++)
			{
				ans2+=max1[n-x+1];
			}
			cout<<max(ans2,ans1)<<endl;
			return 0;
		}
	}
	return 0;
}

