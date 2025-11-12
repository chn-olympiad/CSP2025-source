#include<bits/stdc++.h>
using namespace std;
struct member
{
	int a,b,c;
}a[100005];
struct student
{
	int id,d;
	bool operator>(const student a)const
	{
		return a.d>d;
	}
};
int ans2=0,rc[100005];
int T,n,dp[155][155][155];
void check()
{
	int cnt=0,x1=0,x2=0,x3=0;
	for(int i=1;i<=n;i++)
	{
		if(rc[i]==1)cnt+=a[i].a,x1++;
		else if(rc[i]==2)cnt+=a[i].b,x2++;
		else if(rc[i]==3)cnt+=a[i].c,x3++;	
	}
	if(x1>n/2||x2>n/2||x3>n/2)return;
	ans2=max(ans2,cnt);
}
void dfs(int x)
{
	if(x>n)
	{
		check();
		return;
	}
	rc[x]=1;
	dfs(x+1);
	rc[x]=2;
	dfs(x+1);
	rc[x]=3;
	dfs(x+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		bool flag=true;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0)flag=false;
		}
		int maa=n/2,mab=n/2,mac=n/2,ans=0;
		if(flag)
		{
			int ans1=0;
			for(int i=1;i<=n;i++)
			{
				ans1+=a[i].a;
				if(ans1==n/2)break;
			}
			cout<<ans1<<endl;
			continue;
		}
		if(n<=20)
		{
			ans2=0;
			memset(rc,0,sizeof(rc));
			dfs(1);
			cout<<ans2<<endl;
			continue;
		}
		if(n<=300)
		{
			int ans3=0;
			memset(dp,0,sizeof(dp));
			dp[0][0][0]=0;
			for(int j=0;j<=maa;j++)
				for(int k=0;k<=maa;k++)
				{
					int he=0;
					if(n-j-k>maa)continue;
					for(int i=1;i<=n;i++)
					{
						int sum=0;
						if(n-j-k>=1)sum=max(sum,dp[j][k][n-j-k-1]+a[i].c);
						if(k>=1)sum=max(sum,dp[j][k-1][n-j-k]+a[i].b);
						if(j>=1)sum=max(sum,dp[j-1][k][n-j-k]+a[i].a);
						he+=sum;
					}
					dp[j][k][n-j-k]+=he;
					ans3=max(ans3,dp[j][k][n-j-k]);
				}
			cout<<ans3<<endl;
			continue;
		}
	}
	return 0;
}
