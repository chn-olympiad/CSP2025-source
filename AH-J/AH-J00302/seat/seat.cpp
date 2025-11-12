#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
bool cmp(int x,int y){return x>y;}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[(i-1)*m+j];
	int x=a[1],t=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>0;j--)
			{
				t++;
				if(a[t]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				t++;
				if(a[t]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
