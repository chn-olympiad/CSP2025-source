#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1][m+1];
	int b[n*m+1];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int t=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	t=b[1];
	for(int i=1;i<n*m;i++)
	{
		for(int j=i;j<n*m;j++)
		{
			if(b[i]<b[j])
			{
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==t)
		{
			if(((i-1)/n)%2 == 0)
			{
				cout<<(i-1)/n+1<<' '<<(i-1)%n+1;
			}
			else
			{
				cout<<(i-1)/n+1<<' '<<n-((i-1)%n);
			}
		}
	}
	return 0;
}
