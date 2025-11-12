#include <bits/stdc++.h>//用贪心可以一一枚举 暴力算出最大值 但我不会写 
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,z,x,c,a[1000][1000],sum=0;
	cin>>t>>n;
	int q=n/2;
	for (int tt=1;tt<=t;tt++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if (z>q&&x>q&&c>q)
				{
					continue;
				}
				sort(a[i][j]+1,a[i][j]+n+1);
				reverse(a[i][j]+1,a[i][j]+n+1);
				for (int p=1;p<=q;q++)
				{
					sum+=j;
				}
			}
		}
	cout<<sum;
	}
	return 0;
}
