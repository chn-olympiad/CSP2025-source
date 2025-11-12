#include  <bits/stdc++.h>
using namespace std;
int a[505],b[505],b1[505],b2[505];
int cnt=1,sum;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int z;
	cin>>n>>m;
	cin>>z;
	int x=0;
	while(z>0)
	{
		a[n-x]=z%10;
		z/=10;
		x++;
	}
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			swap(b1[i],b1[j]);
			for(int k=1;k<=n;k++)
			{
				if(a[k]==0)
				{
					sum++;
					continue;
				}
				else
				{
					if(b1[k]-sum>=0)cnt++;
					sum++;
				}
			}
		}
	}
	cout<<cnt;
 	return 0;
}

