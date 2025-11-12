#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s,sp;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			sp=i;
		}
	}
	sp=n*m-sp+1;
	if(sp%n==0)
	{
		cout << sp/n << ' ';
		int y=sp/n-1;
		if(y%2==0)
		{
			cout << n;
		}
		else
		{
			cout << 1;
		}
	}
	else
	{
		cout<<sp/n+1 << ' ';
		int y=sp/n;
		if(y%2==0)
		{
			cout << sp%n;
		}
		else
		{
			cout << n+1-sp%n;
		}
	}
	return 0;
}
