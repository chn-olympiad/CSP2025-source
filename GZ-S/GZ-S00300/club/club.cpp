//GZ-S00300 毕节七星关东辰实验学校 漆高唤 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[4][N];
int T;
int o[N],to[N],th[N],book[N][N];
int ans=0,dp[N];
int cnt1,cnt2,cnt3,sum;
bool cmp1(int x,int y)
{
	return x>y;
}
bool cmp2(int x,int y)
{
	return x>y;
}
bool cmp3(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		cnt1=0;
		cnt2=0;
		cnt3=0;
		ans=0;
		scanf("%d",&n);
	
	sum=n;
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=3;i++)
		{
			scanf("%d",&a[i][j]);
			book[i][j]=0;
		}
		o[j]=a[1][j];
		to[j]=a[2][j];
		th[j]=a[3][j];
	}
	int sum1=n/2;
	sort(o+1,o+n+1,cmp1);
	sort(to+1,to+n+1,cmp2);
	sort(th+1,th+n+1,cmp3);
	if(n==2)
	{
		int ans1=-1;
		ans1=max(ans1,o[1]+to[2]);
		ans1=max(ans1,o[1]+th[2]);
		ans1=max(ans1,to[1]+o[2]);
		ans1=max(ans1,to[1]+th[2]);
		ans1=max(ans1,th[1]+to[2]);
		ans1=max(ans1,th[1]+o[2]);
		cout<<ans1<<endl;
		return 0;
	}
	else
	{
		while(sum1--){

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(o[i]!=0&& to[j]!=0&& th[k]!=0) 
				{
				
				ans=max(ans,o[i]+to[j]+th[k]);
				o[i]=0;
				to[j]=0;
				th[k]=0;
			}
			}
		}
	}
	
	printf("%d\n",ans); 
	}
}
	
}
	return 0;
}
