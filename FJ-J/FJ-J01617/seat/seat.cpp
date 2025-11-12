#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,a[101];
	x=1;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])x++;
	}
	int s=x/n,y=x%n;
	if(y==0)
	{
		if(s%2==0)
		{
			cout<<s<<" 1";
		}
		else
		{
			cout<<s<<" "<<n;
		}
	}
	else
	{
		if(s%2==0)
		{
			cout<<s+1<<" "<<y;
		}
		else
		{
			cout<<s+1<<" "<<n+1-y;
		}
	}
	return 0;
}
