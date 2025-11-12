#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,x=1;
	bool s=0;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(t==a[x])
			{
				if(i%2==1)cout<<i<<' '<<j;
				else cout<<i<<' '<<n-j+1;
				s=1;
				break;
			}
			x++;
		}
		if(s==1)break;
	}
	return 0;
}
