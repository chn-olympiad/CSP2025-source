#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m;
ll r[15][15];
ll pos=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	ll x,y;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>r[i][j];
			if(r[i][j]>r[1][1])
				pos++;
		}
	}
	if(pos%n==0)
	{
		x=pos/n;
		if(x%2==1)
			y=n;
		else
			y=1;
	}
	else
	{
		x=pos/n+1;
		if(x%2==1)
			y=pos%n;
		else
			y=n+1-pos%n;
	}
	cout<<x<<' '<<y;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
