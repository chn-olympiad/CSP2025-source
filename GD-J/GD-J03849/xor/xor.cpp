#include<bits/stdc++.h>
#define int long long
#define sc scanf
#define pr printf
#define fr freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
#define w while
#define f(i,x,n,y) for(int i=x;i<=n;i+=y)
#define st string
using namespace std;
int n,k,a[5874376],sum0,sum1,sum[5890][5378],ans=0,a[4587][4567],cf,ij[937876],ji[674897],y[458873][3];
void dfs(int sum)
{
	f(i,1,cf,1)
	{
		f(j,1,sum,1)
		{
			if(y[j][2]<=y[i][1])
			{
				y[i][1]=ij[i];
				y[i][2]=ji[i];
				dfs(sum+1);
				y[i][1]=0;
				y[i][2]=0;	
			}				
		}		
	}
}
signed main()
{
	fr
	cin>>n>>k; 
	f(i,1,n,1)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		if(n==1)
		{
			cout<<1;
		}
		else
		{
			cout<<n/2;
		}
		return 0;
	}
	if(k==1)
	{
		f(i,1,n,1)
		{
			if(a[i]==1)
			{
				sum1++;
			}
			else
			{
				sum0++;
			}
		}
		cout<<min(sum1,sum0);
		return 0;
	}
	f(l,1,n,1)
	{
		f(r,l,n,1)
		{
			f(i,l,r,1)
			{
				sum[l][r]^=a[i];
			}		
		}
	}
	f(i,1,n,1)
	{
		f(j,i,n,1)
		{
			if(sum[i][j].cc==k)
			{
				a[i][j]=1;
				ij[++cf]=i;
				ji[cf]=j;
				break;
			}
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
