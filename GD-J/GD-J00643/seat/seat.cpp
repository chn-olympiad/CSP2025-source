#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
struct node
{
	int num,x;
}arr[105];
bool cmp(node p,node q)
{
	return p.x>q.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		arr[i].num=i;
		cin>>arr[i].x;
	}
	sort(arr+1,arr+n*m+1,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(arr[k++].num==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(arr[k++].num==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
