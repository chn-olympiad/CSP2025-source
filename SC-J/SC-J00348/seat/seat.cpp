#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{ 
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int k=0;
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[++k]==r)
			{
				cout<<i<<' '<<j;
				return 0;
			}
		}
		for(int j=n;j>=1;j--)
		{
			if(a[++k]==r)
			{
				cout<<i+1<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}