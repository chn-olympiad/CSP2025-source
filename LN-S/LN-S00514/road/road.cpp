#include<bits/stdc++.h>
using namespace std;
int q[1000005];
long long int a[100000][4];
int k1[15][1005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>k1[i][j];
		}
	}
	int b[100005];
	for(int i=1;i<=m;i++)
	{
		b[i]=a[i][3];
	}
	for(int i=m;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(b[j]>b[j+1])
			{
				swap(b[j],b[j+1]);
			}
		}
	}
	int cnt=0;
	if(k==0)
	{
		for(int i=1;i<=n-1;i++)
		{
			cnt=cnt+b[i];
		}
	    cout<<cnt;
	}
    return 0;
}
