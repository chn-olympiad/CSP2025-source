#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],b[1001][1001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int k=1;
	for(int i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=m;j++)
			{
				b[j][i]=a[k];
				k++;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				b[j][i]=a[k];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==x) cout<<j<<" "<<i;
		}
	}
    return 0;
}
