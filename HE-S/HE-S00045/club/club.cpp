#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int N=2e4+520;
int a[N][5];
int ci[5];
long long ans;
bool okb;
bool oka;
int aa[N]; 
int m;
void dfs(int k,long long sum)
{
	if(k>n)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(ci[i]>=m)
		{
			continue;
		}
		else
		{
			sum+=a[k][i];
			ci[i]++;
			dfs(k+1,sum);
			sum-=a[k][i];
			ci[i]--;
		}
	}
}
int f[N][3];
int dp[N];
void dfs2(int k)
{
	if(k>n)
	{
		return ;
	}
	for(int i=1;i<=2;i++)
	{
		{
			f[i][1]=max(f[i-1][1],f[i-1][2])+a[i][1];
			ci[1]++;
			dfs2(k+1);
			ci[1]--;
			f[i][2]=f[i][1]=max(f[i-1][1],f[i-1][2])+a[i][2];
			ci[2]++;
			dfs2(k+1);
		}
	}
}
int main()
//搜索不会写，难道只能写dp了 
//k+1和k++不一样？？？！！！！@！！！，对的莫名其妙 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		oka=true;
		okb=true;
		m=n/2;
		ans=0;
		for(int i=1;i<=3;i++)
		{
			ci[i]=0;
		}
		//sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
			if(a[i][2]!=0)
			{
				oka=false;
			}
			if(a[i][3]!=0)
			{
				oka=false;
				okb=false;
			}
			aa[i]=a[i][1];
		}
		if(n<=10)
		{
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		else if(oka==true)
		{
			//排序1e5会不会t
			sort(aa+1,aa+1+n);
			for(int i=m+1;i<=n;i++)
			{
				ans+=aa[i];
			}
			cout<<ans<<endl;
			continue;
		}
		//直接开争，dp； 
		else if(okb==true)
		{
			dfs(1,0);
			continue;
		}
		else
		{
			dfs(1,0);
			continue;
		}
	}
	return 0;
}
