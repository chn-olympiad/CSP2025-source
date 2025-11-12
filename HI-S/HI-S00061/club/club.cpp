#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,a[5][100005],ans,a1[100005],a2[100005],a3[100005],max1,max2,max3;

void dfs(int step,int f1,int f2,int f3,int cnt)
{
	if(f1>n/2||f2>n/2||f3>n/2)return;
	if(step==n+1)
	{
		ans=max(ans,cnt);
		return;
	}
	dfs(step+1,f1+1,f2,f3,cnt+a[1][step]);
	dfs(step+1,f1,f2+1,f3,cnt+a[2][step]);
	dfs(step+1,f1,f2,f3+1,cnt+a[3][step]);
}
//void solve()
//{
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			for(int k=1;k<=n;k++)
//			{
//				if(i!=j&&j!=k&&i!=k)
//				{
//					
//				}
//			}
//		}
//	}
//}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		max1=max2=max3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i];
			a1[i]=a[1][i];
			max1=max(max1,a1[i]);
			cin>>a[2][i];
			a2[i]=a[2][i];
			max2=max(max2,a2[i]);
			cin>>a[3][i];
			a3[i]=a[3][i];
			max3=max(max3,a3[i]);
			a[4][i]=max(a[1][i],max(a[2][i],a[3][i]));
		}
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
//		else if(n<=200)
//		{
//			solve();
//			continue; 
//		}
		else if(max2==max3&&max2==0)
		{
			sort(a1+1,a1+(n/2)+1,cmp);
			for(int i=1;i<=(n/2);i++)
			{
				ans+=a1[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				ans+=a[4][i];
			}
			cout<<ans<<"\n";
		}
	}
} 
