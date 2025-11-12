#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id,sum;
}a[500];
int n,m,cnt=1;
bool cmp(node x,node y)
{
	return x.sum>y.sum;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;++i)
	{
		cin>>a[i].sum;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;++i)
	{
		if(a[i].id==1)
		{
			break;
		}
	}
	cnt=1;
	for(int i = 1;i<=n;++i)
	{
		if(i%2)
		{
			for(int j = 1;j<=m;++j)
			{
				if(a[cnt].id==1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		else
		{
			for(int j = m;j>=1;--j)
			{
				if(a[cnt].id==1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}
