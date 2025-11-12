#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt;
int a[105];
int x[15][15];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				x[j][i]=a[++cnt];
				if(x[j][i]==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				x[j][i]=a[++cnt];
				if(x[j][i]==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
 } 
