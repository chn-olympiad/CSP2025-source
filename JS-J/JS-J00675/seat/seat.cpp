#include<bits/stdc++.h>
using namespace std;
int f[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin>>n>>m;
	int j=n;
	for(int i=1; i<=n*m; i++)
	{
		cin>>f[i];
	}
	int a=1;
	for(int i=2; i<=n*m; i++)
	{
		if(f[i]>f[1])
		{
			a++;
		}
	}
	int y=(a+n-1)/n;
	int x=a%n;
	if(y%2==0)
	{
		x=n-x+1;
	}
	if(x==0)
	{
		cout<<y<<' '<<n<<endl;
		return 0;
	}
	while(x>j)
	{
		x=x-j;
	}
	cout<<y<<' '<<x<<endl;
	
	return 0;
}
