#include<bits/stdc++.h>
using namespace std;
long long n,pp;
struct edge{
	int x,y,z;
	long long sum;
}p[100005];
bool cmp(edge a,edge b)
{
	return a.sum>b.sum;
}
bool cmp1(edge a,edge b)
{
	return a.x>b.x;
}
//void dfs(int k,long long ans,int c1,int c2,int c3)
//{
//	
//	if(k>=n)
//	{
//		if(c1<n/2 && c2<n/2 && c3<n/2)
//		{
//			pp=max(pp,ans-1);
//		}
//		return;
//	}
//	//int ma=max(p[k].x,max(p[k].y,p[k].z)),mi=min(p[k].x,min(p[k].y,p[k].z));
//	//int zws=p[k].sum-ma-mi;
//	for(int j=1;j<=n;j++)
//	{
//		dfs(k+1,ans+max(p[k].x,max(p[k].y,p[k].z)),c1+1,c2,c3);
//		dfs(k+1,ans+max(p[k].x,max(p[k].y,p[k].z)),c1,c2+1,c3);
//		dfs(k+1,ans+max(p[k].x,max(p[k].y,p[k].z)),c1,c2,c3+1);
//		dfs(k+1,ans+min(p[k].x,min(p[k].y,p[k].z)),c1+1,c2,c3);
//		dfs(k+1,ans+min(p[k].x,min(p[k].y,p[k].z)),c1,c2+1,c3);
//		dfs(k+1,ans+min(p[k].x,min(p[k].y,p[k].z)),c1,c2,c3+1);
//		dfs(k+1,ans+p[k].sum-max(p[k].x,max(p[k].y,p[k].z))-min(p[k].x,min(p[k].y,p[k].z)),c1+1,c2,c3);
//		dfs(k+1,ans+p[k].sum-max(p[k].x,max(p[k].y,p[k].z))-min(p[k].x,min(p[k].y,p[k].z)),c1,c2+1,c3);
//		dfs(k+1,ans+p[k].sum-max(p[k].x,max(p[k].y,p[k].z))-min(p[k].x,min(p[k].y,p[k].z)),c1,c2,c3+1);
//	}
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int f1=0,f2=0,f3=0; 
		pp=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].x>>p[i].y>>p[i].z;
			p[i].sum=p[i].x+p[i].y+p[i].z;
			if(p[i].z) f3=1;
			if(p[i].x) f1=1;
			if(p[i].y) f2=1;
		}
		if(!f2&&!f3) 
		{
			sort(p+1,p+n+1,cmp1);
			for(int i=1;2*i<=n;i++)
			{
				ans+=p[i].x;
			}
			cout<<ans;
		}
		sort(p+1,p+n+1,cmp);
		int cnt[10]={0};
		for(int i=1;i<=n;i++)
		{
			int ma=max(p[i].x,max(p[i].y,p[i].z)),mi=min(p[i].x,max(p[i].y,p[i].z));
			if(ma==p[i].x)
			{
				if(2*cnt[1]<n)
				{
					ans+=p[i].x;
					cnt[1]++;
				}
				else
				{
					if(mi==p[i].y)
					{
						if(2*cnt[3]<n)
						{
							ans+=p[i].z;
					   		cnt[3]++;
						}
						else
						{
							ans+=p[i].y;
							cnt[2]++;
						}
					}
					else
					{
						if(2*cnt[2]<n)
						{
							ans+=p[i].y;
							cnt[2]++;
						}
						else
						{
							ans+=p[i].z;
							cnt[3]++;
						}
					}
				}
			}
			else if(ma==p[i].y)
			{
				if(2*cnt[2]<n)
				{
					ans+=p[i].y;
					cnt[2]++;
				}
				else
				{
					if(mi==p[i].x)
					{
						if(2*cnt[3]<n)
						{
							ans+=p[i].z;
							cnt[3]++;
						}
						else
						{
							ans+=p[i].x;
							cnt[1]++;
						}
					}
					else
					{
						if(2*cnt[1]<n)
						{
							ans+=p[i].x;
							cnt[1]++;
						}
						else
						{
							ans+=p[i].z;
							cnt[3]++;
						}
					}
				}
			}
			else if(ma==p[i].z)
			{
				if(2*cnt[3]<n)
				{
					ans+=p[i].z;
					cnt[3]++;
				}
				else
				{
					if(mi==p[i].y)
					{
						if(2*cnt[1]<n)
						{
							ans+=p[i].x;
							cnt[1]++;
						}
						else
						{
							ans+=p[i].y;
							cnt[2]++;
						}
					}
					else
					{
						if(2*cnt[2]<n)
						{
							ans+=p[i].y;
							cnt[2]++;
						}
						else
						{
							ans+=p[i].x;
							cnt[1]++;
						}
					}
				}
			}
		} 
		
		cout<<ans<<endl;
	}
}
