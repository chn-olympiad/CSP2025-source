#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int read()
{
	int ans=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
int n;
int a[5005],ans,vis[5005],v[2][2][2][2][2][2][2][2][2][2],maxn=-1e8;
bool cheak(int step)
{
	int res=0,maxn=-1e8;
	for(int i=1;i<=step;i++)
	{
		if(vis[i]==1)
		{
			res+=a[i];
			maxn=max(maxn,a[i]);
		}
	}
	if(res>maxn*2&&step>=3)
	{
		return true;
	}
	return false;
	
}
void dfs(int step)
{
	if(cheak(step))
	{
		v[vis[1]][vis[2]][vis[2]][vis[4]][vis[5]][vis[6]][vis[7]][vis[8]][vis[9]][vis[10]]=1;
	}
	if(step==n+1)
	{
		return;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	dfs(step+1);
}
int ksm(int a,int b,int p)
{
	int res=1;
	while(b)
	{
		if(b%2==1)res=res*a%p;
		a=a*a%p;
		b/=2;
	}
	return res;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(maxn==1)
	{
		for(int i=3;i<=n;i++)
		{
			int res1=1,res2=1,res=1;
			for(int j=n;j>=n-i+1;j--)
			{
				res1=res1*j%p;
			}
			for(int j=1;j<=i;j++)
			{
				res2=res2*j%p;
			}
			res=res1/res2;
			ans=(ans+res)%p;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	for(int ia=0;ia<=1;ia++)
	{
		for(int ib=0;ib<=1;ib++)
		{
			for(int ic=0;ic<=1;ic++)
			{
				for(int id=0;id<=1;id++)
				{
					for(int ie=0;ie<=1;ie++)
					{
						for(int ig=0;ig<=1;ig++)
						{
							for(int ih=0;ih<=1;ih++)
							{
								for(int ii=0;ii<=1;ii++)
								{
									for(int ij=0;ij<=1;ij++)
									{
										for(int ik=0;ik<=1;ik++)
										{
											ans+=v[ia][ib][ic][id][ie][ig][ih][ii][ij][ik];
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
}
