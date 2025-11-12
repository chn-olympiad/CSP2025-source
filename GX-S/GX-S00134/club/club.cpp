#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long ans=0;
long long sum=0;
int n=0;
long long p1=0,p2=0,p3=0;
struct mem
{
	int a1=0;
	int a2=0;
	int a3=0;
}a[N];
void dfs(int depth)
{
	if(p1>n/2||p2>n/2||p3>n/2)//jian zhi
	{
		return ;
	}
	if(depth>n)
	{
		ans=max(ans,sum);
		return ;
	}
	else
	{
		for(int i=1;i<=3;i++)//xuan bu men
		{
			if(i==1)
			{
				if(p1<=(n/2)-1)
				{
					sum=a[depth].a1+sum;
					p1++;
				}
				else
				{
					continue;
				}
			}
			if(i==2)
			{
				if(p2<=(n/2)-1)
				{
					sum=a[depth].a2+sum;
					p2++;
				}
				else
				{
					continue;
				}
			}
			if(i==3)
			{
				if(p3<=(n/2)-1)
				{
					sum=a[depth].a3+sum;
					p3++;
				}
				else
				{
					continue;
				}
			}
			////////////////////
			dfs(depth+1);
			////////////////////gui wei sum, p
			if(i==1)
			{
				sum-=a[depth].a1;
				p1--;
			}
			if(i==2)
			{
				sum-=a[depth].a2;
				p2--;
			}
			if(i==3)
			{
				sum-=a[depth].a3;
				p3--;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{	
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
		}
		dfs(1);
		cout<<ans<<"\n";	
		ans=0;
	}
	return 0;
}
