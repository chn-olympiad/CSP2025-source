#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int x;
		cin>>x;
		b[i]=x;
		a[x]++;
	}
	int o,sum=0;
	for(int i=100;i>=1;i--)
	{
		if(a[i])
			sum++;
		if(i==b[1])
		{
			o=sum;
			break;
		}
	}
	int y,z;
	if(o%n==0)
	{
		y=o/n;
	}
	else
		y=o/n+1;
	if(y%2==0&&o%n==0)
		z=1;
	else if(y%2==0)
		z=(n-o%n)+1;
	if(y%2==1&&o%n==0)
		z=n;
	else if(y%2==1)
		z=o%n;
	cout<<y<<' '<<z;
	return 0;
}

