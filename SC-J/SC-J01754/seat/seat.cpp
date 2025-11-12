#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
		{
			cnt++;
		}
	}
	cnt++;
	cout<<(cnt-1)/n+1<<" ";
	if((cnt-1)/n%2==0)
	{
		cout<<(cnt-1)%n+1;
	}
	else
	{
		cout<<n-(cnt-1)%n;
	}
	return 0;
}