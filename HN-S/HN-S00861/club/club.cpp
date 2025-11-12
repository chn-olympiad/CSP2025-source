#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
long long T, n;
long long c[N][N], a[N][N];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>T;
	while(T--)
	{
		long long mmin = 1e6 + 10, sum = 0, maxn[N], mid[N], b[N], d[N];
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			mid[i] = 1e6 + 10;
			maxn[i] = 0, b[i] = 0, d[i] = 1;
		}
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(maxn[i] < a[i][j])
				d[i] = j;
				
				maxn[i]=max(maxn[i], a[i][j]);
			}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				c[i][j]=maxn[i] - a[i][j];
					
			for(int k=1;k<=3;k++)
			{
				if(k != d[i])
				mid[i] = min(mid[i], c[i][k]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j] == maxn[i])
				{
					if(b[j] < (n/2))
					{
						sum += a[i][j];
						b[j]++;
						break;
					}
					if(b[j] >= (n/2))
					{
						for(int k=1;k<=i;k++)
							mmin = min(mmin, mid[k]);
						 
						for(int k=1;k<=i;k++)
						{
							if(mid[k] == mmin)
							{
								sum-=mid[k];
								sum+=a[i][j];
								break;
							}
						}
						break;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
