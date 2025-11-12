#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
	freopen("seat,in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int num=a[1];
	sort(a,sizeof(a));
	for(int i=1;i<=n*m;i++)
	{
		if(n+1-i==num)
		{
			cout<<(i-1)/n+1<<' ';
			if(((i-1)/n+1)%2)
			{
				if(i%n)
					cout<<i%n;
				else
					cout<<n;
			}
			else
			{
				if(i%n)
					cout<<1;
				else
					cout<<n-i%n;
			}
		}
	}
	return 0;
}
