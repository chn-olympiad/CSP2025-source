#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,a[N],k,mp[N][N],id;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
//		cout<<a[i]<<' ';
		if(k==a[i])
		{
			id=i;
			break;
		}
	}
	k=id;
	id=0;
//	cout<<k<<' '; 
	for(int j=1;j<=m;j++)
	{
		if(j%2)
		{
			for(int i=1;i<=n;i++)
			{
				id++;
				if(id==k)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				id++;
				if(id==k)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
//	if((id/n+1)%2==0)
//	{
//		cout<<id/n+1<<' '<<n-(id%n);
//	}
//	else if(id%n!=0)cout<<id*1.0/n+1<<' '<<id%n;
//	else if(id%n==0)cout<<id*1.0/n+1<<' '<<m;
	return 0;
}
