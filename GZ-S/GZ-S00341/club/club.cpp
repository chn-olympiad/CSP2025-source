//GZ-S00341 贵阳市第三实验中学 王轶璋 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][4];
int dfs(int x,int I,int II,int III,int sum)
{
	if(x>n)
	{
		return sum;
	}
	int ans=0;
	if(I<n/2)
	{
		ans=max(dfs(x+1,I+1,II,III,sum+a[x][1]),ans);
	}
	if(II<n/2)
	{
		ans=max(dfs(x+1,I,II+1,III,sum+a[x][2]),ans);
	}
	if(III<n/2)
	{
		ans=max(dfs(x+1,I,II,III+1,sum+a[x][3]),ans);
	}
	return ans; 
}
void solve()
{
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]!=0&&!flag)
		{
			flag=1;
		}
		else if(a[i][2]!=0&&!flag)
		{
			flag=2;
		}
		else if(a[i][2]!=0&&!flag)
		{
			flag=3;
		}
		if(flag)
		{
			if(a[i][1]+a[i][2]+a[i][3]!=a[i][flag])
			{
				flag=-1;
			}
		}
	}
	if(flag>0)
	{
		int f[N];
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			for(int j=n/2;j>=1;j--)
			{
				f[j]=max(f[i],f[j-1]+a[i][flag]);
			}
		}
		cout<<f[n/2]<<endl;
	}
	else
	{
		cout<<dfs(1,0,0,0,0)<<endl;
//		int f[N][4];
//		memset(f,0,sizeof(f));
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=n/2;j>=1;j--)
//			{
//				for(int k=1;k<=3;k++)
//				{
//					f[i][k]=max({f[i-1][k],f[i-1][1]+a[i][k],f[i-1][2]+a[i][k],f[i-1][3]+a[i][k]});
//				}
//			}
//		}
		//cout<<max({f[n][1],f[n][2],f[n][3]})<<endl;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
