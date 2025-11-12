/*
	Date: 2025年11月1日16:12:36 
	I_think_My_Mark: 25 pts 
*/
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],ans;
int df[100010];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int k)//#1、2、3、4 
{
	if(k>n)
	{
		int cnt=0,c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++)
		{
			if(df[i]==1)
			{
				cnt+=a[i];
				c1++;
			}
			else if(df[i]==2)
			{
				cnt+=b[i];
				c2++;
			}
			else
			{
				cnt+=c[i];
				c3++;
			}
		}
		if(c1+c2<c3||c1+c3<c2||c2+c3<c1)
		{
			return;
		}
		ans=max(ans,cnt);
		return;
	}
	for(int i=k;i<=n;i++)
	{
		df[i]=1;
		dfs(i+1);
		df[i]=2;
		dfs(i+1);
		df[i]=3;
		dfs(i+1);
	}
}
void solve1()//#12-----特性 A 
{
	int cnt=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++)
	{
		cnt+=a[i];
	}
	cout<<cnt<<"\n";
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==2)//#1
		{
			int s1,s2,s3,d1,d2,d3;
			cin>>s1>>s2>>s3>>d1>>d2>>d3;
			cout<<max({s1+d2,s1+d3,s2+d1,s2+d3,s3+d1,s3+d2})<<"\n";
		}
		else
		{
			ans=0;
			int c1=0,c2=0;
			bool flag_A=1;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i]>>b[i]>>c[i];
				if(b[i]!=0||c[i]!=0)
				{
					flag_A=0;
				}
			}
			if(flag_A)
			{
				solve1();
			}
			else
			{	
				dfs(1);
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
