#include <iostream>
#include <cstdio>
using namespace std;

int m,n,a,b[105],cnt=1,mn;
int main()
{
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	cin>>n>>m;
	cin>>a;
	mn=m*n;
	for (int i=2;i<=mn;i++)
	{
		cin>>b[i];
		if (b[i]>a)
			cnt++;
	}
	for (int i=1;i<=m;i++)
	{
		if (cnt<=n)
		{
			if (i%2==0)
			{
				cout<<i<<' '<<n-cnt+1;
			}
			else
				cout<<i<<' '<<cnt;
			return 0;
		}
		cnt-=n;
	}
	return 0;
}
