#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,s,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			x=n*m-i+1;
			break;
		}
	}
	int y=x/n;
	int z=x-y*n;
	if(z==0)
	{
		z=n;
		y--;
	}
	if((y+1)%2==1)
	{
		cout<<y+1<<" "<<z;
	}
	else
	{
		cout<<y+1<<" "<<n-z+1;
	}
	return 0;
}
