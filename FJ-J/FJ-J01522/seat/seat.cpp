#include <bits/stdc++.h>
using namespace std;
int n,m,a[510],l,ans[110][110],j=1,k=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>l;
	a[1]=l;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		ans[j][k]=a[i];
		if(k%2==1)
		{
			if(j<n) j++;
			else if(j==n) k++;
		}
		else
		{
			if(j>1) j--;
			else if(j==1) k++;
		}
	}
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=m;y++)
		{
			if(ans[x][y]==l)
			{
				cout<<y<<' '<<x;
				return 0;
			}
		}
	}
	return 0;
}
