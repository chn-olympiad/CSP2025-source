#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,x;
int tot,a[100][100];
struct point{
	int data;
	bool R;
}scores[1000];
bool cmp(point a,point b)
{
	return a.data>b.data;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++)
	{
		cin>>scores[i].data;
		if(i==1)
		{
			scores[i].R=true;
		}
	}
	sort(scores+1,scores+x+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				a[i][j]=scores[++tot].data;
				if(scores[tot].R)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		} 
		else
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=scores[++tot].data;
				if(scores[tot].R)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
}
