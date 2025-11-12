#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5+5;
int T;
int n;
int ans;
int a[N][5];
int f[205][100][100];
bool used[N];

void dfs(int numa,int numb,int numc,int sum)
{
	if(numa+numb+numc==n)
	{
		ans = max(ans,sum);
		return ;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			used[i] = true;
			if(numa+1<=n/2) dfs(numa+1,numb,numc,sum+a[i][1]);
			if(numb+1<=n/2) dfs(numa,numb+1,numc,sum+a[i][2]);
			if(numc+1<=n/2) dfs(numa,numb,numc+1,sum+a[i][3]);
			used[i] = false;
		}
	}
}

int Max(int a,int b,int c,int d)
{
	return max(a,max(b,max(c,d)));
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		
		if(n>5)
		{
			int ans = 0;
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=i;j++)
				{
					if(j>i/2) break;
					for(int k=0;k+j<=i;k++)
					{
						if(k>i/2) break;
						int x = j;
						int y = k;
						int z =i-j-k;
						
						if(x<0||y<0||z<0) continue;
						f[i][j][k] = Max(f[i][j][k],f[i-1][j-1][k]+a[i][1],f[i-1][j][k-1]+a[i][2],f[i-1][j][k]+a[i][3]);
						ans = max(ans,f[i][j][k]);
					}
				}
			}
			
			cout<<ans<<'\n';
			continue;
		}
		
		ans = 0;
		dfs(0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
